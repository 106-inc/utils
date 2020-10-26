#!/usr/bin/env python3

trans_d = {
    'а': 'a',
    'б': 'b',
    'в': 'v',
    'г': 'g',
    'д': 'd',
    'е': 'e',
    'ё': 'yo',
    'ж': 'zh',
    'з': 'z',
    'и': 'i',
    'й': 'y',
    'к': 'k',
    'л': 'l',
    'м': 'm',
    'н': 'n',
    'о': 'o',
    'п': 'p',
    'р': 'r',
    'с': 's',
    'т': 't',
    'у': 'u',
    'ф': 'f',
    'х': 'kh',
    'ц': 'ts',
    'ч': 'ch',
    'ш': 'sh',
    'щ': 'shch',
    'ъ': '',
    'ы': 'y',
    'ь': "'",
    'э': 'e',
    'ю': 'yu',
    'я': 'ya',
}


def main():
    print('Input amount of words: ')
    N = int(input())

    words = []
    for i in range(N):
        words.append(input())

    for word in words:
        for let in word:

            if let.lower() not in trans_d:
                print(let, end='')
                continue

            res = ''
            if let.isupper():
                res = trans_d[let.lower()].upper()
            else:
                res = trans_d[let]

            print(res, end='')

        print('')


if __name__ == '__main__':
    main()
