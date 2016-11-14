#! /usr/bin/env python

import json
from MidstateBigEndian import calculateMidstate as be_calculateMidstate

def readflip(data, size):
	return (('%.' + str(size) + 'X') % data).decode('hex')[::-1]

with open('testcases.json') as f:
	data = json.load(f)

final = []

for d in  data:
	version = readflip(d['ver'], 8)
	prev_block = readflip(int('0x' + d['prev_block'], 0), 64)
	merkle_root = readflip(int('0x' + d['mrkl_root'], 0), 64)
	nonce = readflip(d['nonce'], 8)
	time = readflip(d['time'], 8)
	bits = readflip(d['bits'], 8)

	diff = d['bits']
	target = (diff & 0xFFFFFF) * 2 ** (8 * ((diff >> 24) - 3))

	payload = ((version + prev_block + merkle_root + time + bits + nonce).encode('hex_codec'))
	result = d['hash']

	mid = be_calculateMidstate(payload.decode('hex')[:64]).encode('hex_codec')

	final.append({'payload': payload, 'result': result, 'target':'%.64X' % target, 'nonce': '%.8X' % d['nonce'], 'midstate': mid, 'header': d})

with open('pptestcases.json', 'w') as f:
	json.dump(final, f)

