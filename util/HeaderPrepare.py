#! /usr/bin/env python

import midstate
import hashlib
import struct

from MidstateBigEndian import calculateMidstate as be_calculateMidstate

header_hex = ("01000000" + # Version (byte reversed)
	"81cd02ab7e569e8bcd9317e2fe99f2de44d49ab2b8851ba4a308000000000000" + # Prev hash (big endian)
	"e320b6c2fffc8d750423db8b1eb942ae710e951ed797f7affc8892b0f1fc122b" + # Merkel root (big endian)
	"c7f5d74d" + # time (byte reversed)
	"f2b9441a" + # target (byte reversed)
	"42a14695")  # nonce (byte reversed, but doesn't matter)

header_hex = "000000206772e82eb8fedebfec91ecb1633d711929b12ff9affae103000000000000000051f8345968d7b15d5cf7ced1e5f84e5489b873807f8fb10e86a3832815274c646c51f957c44004189c9a4fcb"

def main_test():
	print('Some other testing...')
	test_chunk = "0100000076C470C5F0B3AD4A9F619598B80090549E781AB575EA587F977000000000000064A03C10396CC7F820F8830614E94330C4FCA76642BC6E0ED8C2BC8F"
	test_chunk = "00000001c570c4764aadb3f09895619f549000b8b51a789e7f58ea750000709700000000103ca064f8c76c390683f8203043e91466a7fcc40e6ebc428fbcc2d8"
	test_midstate = midstate.calculateMidstate(test_chunk.decode('hex'))
	print('Sanity midstate: %s' % test_midstate.encode('hex_codec'))
	print('Should match:    %s' % 'e772fc6964e7b06d8f855a6166353e48b2562de4ad037abc889294cea8ed1070')
	print('or:              %s' % '69fc72e76db0e764615a858f483e3566e42d56b2bc7a03adce9492887010eda8')

	# main()

	header_bin = header_hex.decode('hex')
	first_hash = hashlib.sha256(header_bin).digest()
	final_hash = hashlib.sha256(first_hash).digest()

	print('Input: %s' % header_hex)
	print('First hash: %s' % first_hash.encode('hex_codec'))
	print('Final hash: %s' % final_hash.encode('hex_codec'))

	first_bin = header_bin[:64]
	first_midstate = be_calculateMidstate(first_bin)

	rest_of_bin = header_bin[64:]
	padding = ('80' + ''.join(['00' for x in range(45)]) + '0280').decode('hex')
	print('First midstate: %s' % first_midstate.encode('hex_codec'))
	print('Second input: %s' % (rest_of_bin + padding).encode('hex_codec'))
	final_state = be_calculateMidstate(rest_of_bin + padding, state=first_midstate)
	print('Final state one:  %s' % final_state.encode('hex_codec'))
	print('We want to match: %s' % first_hash.encode('hex_codec'))

	print('Second hash with padding: %s' % (final_state.encode('hex_codec') + ('80' + ''.join(['00' for x in range(29)]) + '0100')))
	solution_hash = be_calculateMidstate(final_state + ('80' + ''.join(['00' for x in range(29)]) + '0100').decode('hex'))
	print('Solution: %s' % solution_hash[::-1].encode('hex_codec'))


def aux_test():
	test_string="6162636462636465636465666465666765666768666768696768696a68696a6b696a6b6c6a6b6c6d6b6c6d6e6c6d6e6f6d6e6f706e6f7071"
	padding = '80' + ''.join(['00' for x in range(69)]) + '01c0'

	test_bin = test_string.decode('hex')
	padding_bin = padding.decode('hex')

	message = test_bin + padding_bin

	first_part = message[:64]
	second_part = message[64:]

	first_hash = be_calculateMidstate(first_part)
	print('First part: %s' % first_hash.encode('hex_codec'))
	second_hash = be_calculateMidstate(second_part, state=first_hash)
	print('Second part: %s' % second_hash.encode('hex_codec'))
	print('Aiming for : %s' % hashlib.sha256(test_bin).digest().encode('hex_codec'))

if __name__ == "__main__":
	main_test()