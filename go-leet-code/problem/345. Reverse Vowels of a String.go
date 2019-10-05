package problem

func reverseVowels(s string) string {
	var str []byte
	str = []byte(s)

	i, j := 0, len(s)-1
	for i < j {
		if isVowel(str[i]) == false {
			i++
		} else if isVowel(str[j]) == false {
			j--
		} else {
			str[i], str[j] = str[j], str[i]
			j--
			i++
		}
	}
	return string(str)
}

func isVowel(b byte) bool {
	return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' ||
		b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U'

}
