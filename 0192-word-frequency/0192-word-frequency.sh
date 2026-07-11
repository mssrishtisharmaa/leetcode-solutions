# Read from the file words.txt and output the word frequency list to stdout.
awk '{for(i=1;i<=NF;i++) freq[$i]++} END{for(word in freq) print word, freq[word]}' words.txt | sort -k2 -nr