package main

import (
	"strings"
)

func getBucketString(word string) string {
	vowle := map[rune]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
	}

	ret := make([]rune, 0)

	for _, ch := range word {
		if vowle[ch] {
			ret = append(ret, '_')
		} else {
			ret = append(ret, ch)
		}
	}
	return string(ret)
}

func spellchecker(wordlist []string, queries []string) []string {
	result := make([]string, 0, len(queries))

	match := make(map[string]bool, len(wordlist))
	caseInsensative := make(map[string]string, len(wordlist))
	bucketVowel := make(map[string]string, len(wordlist))

	for _, word := range wordlist {
		match[word] = true
		lws := strings.ToLower(word)
		if _, ok := caseInsensative[lws]; ok == false {
			caseInsensative[lws] = word
		}
		bucketWord := getBucketString(strings.ToLower(word))
		// fmt.Println("bucket word", bucketWord)
		if _, ok := bucketVowel[bucketWord]; ok == false {
			bucketVowel[bucketWord] = word
		}
	}

	for _, query := range queries {
		if _, ok := match[query]; ok != false {
			result = append(result, query)
			continue
		}
		lQuery := strings.ToLower(query)

		if word, ok := caseInsensative[lQuery]; ok != false {
			result = append(result, word)
			continue
		}

		bucketQuery := getBucketString(strings.ToLower(query))
		if word, ok := bucketVowel[bucketQuery]; ok != false {
			result = append(result, word)
			continue
		}

		result = append(result, "")
	}

	return result
}
