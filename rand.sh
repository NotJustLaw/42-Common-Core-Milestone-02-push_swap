#/bin/bash

for i in $(seq 1 100); do
	RANDOM_SEQ_100=$(seq -1 100 | shuf -n 100)
done
	make re; valgrind --show-leak-kinds=all ./push_swap $RANDOM_SEQ_100 > test_output.txt;
	cat test_output.txt | wc -l

# ARG=$(seq 0 499 | shuf | tr '\n' ' ')
# ./push_swap $ARG | ./checker_linux $ARG
