#! /usr/bin/env python

import requests
import json

def main():
	latest_hash = requests.get('https://blockchain.info/q/latesthash').text
	final = []

	for i in range(200):
		print('Hash %d is %s' % (i, latest_hash))

		payload = requests.get('https://blockchain.info/rawblock/' + latest_hash, params={'format': 'json'}).json()
		del payload['tx']
		final.append(payload)
		latest_hash = payload['prev_block']

	with open('testcases.json', 'w') as f:
		json.dump(final, f)

if __name__ == "__main__":
	main()