import base64
def decode_base64(encoded_string):
    try:
        decoded_bytes = base64.b64decode(encoded_string)
        decoded_string = decoded_bytes.decode('utf-8')
        return decoded_string
    except Exception as e:
        print("Error decoding base64:", e)
        return None

encoded_string = "Um9zaGFuIGdldCBnb29k"
decoded_string = decode_base64(encoded_string)
print("Decoded string:", decoded_string)