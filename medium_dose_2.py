# Morse code dictionary
morse_dict = {
    ".-": "A", "-...": "B", "-.-.": "C", "-..": "D", ".": "E",
    "..-.": "F", "--.": "G", "....": "H", "..": "I", ".---": "J",
    "-.-": "K", ".-..": "L", "--": "M", "-.": "N", "---": "O",
    ".--.": "P", "--.-": "Q", ".-.": "R", "...": "S", "-": "T",
    "..-": "U", "...-": "V", ".--": "W", "-..-": "X", "-.--": "Y",
    "--..": "Z",

    "-----": "0", ".----": "1", "..---": "2", "...--": "3",
    "....-": "4", ".....": "5", "-....": "6", "--...": "7",
    "---..": "8", "----.": "9"
}

def decode_morse(morse_code):
    words = morse_code.strip().split("   ")  # 3 spaces = new word
    decoded_message = ""

    for word in words:
        letters = word.split(" ")
        for letter in letters:
            decoded_message += morse_dict.get(letter, "")
        decoded_message += " "

    return decoded_message.strip()


# Example
msg = "... --- ..."
print(decode_morse(msg))   # SOS