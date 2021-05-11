gen_num: GenerateNumbers.c
	gcc GenerateNumbers.c -o Numbers
del_num: Numbers
	rm -f Numbers
gen_word: GenerateWords.c
	gcc GenerateWords.c -o Words
del_word: Words
	rm -f Words
num_bubble: NumBubbleSort.c
	gcc NumBubbleSort.c -o BubbleSortedNum
word_bubble: WordBubbleSort.c
	gcc WordBubbleSort.c S_swap.c -o BubbleSortedWord
del_num_bubble: BubbleSortedNum
	rm -f BubbleSortedNum
del_word_bubble: BubbleSortedWord
	rm -f BubbleSortedWord
num_selection: NumSelectionSort.c
	gcc NumSelectionSort.c -o SelectionSortedNum
word_selection: WordSelectionSort.c
	gcc WordSelectionSort.c S_swap.c -o SelectionSortedWord
del_num_selection: SelectionSortedNum
	rm -f SelectionSortedNum
del_word_selection: SelectionSortedWord
	rm -f SelectionSortedWord
num_insertion: NumInsertionSort.c
	gcc NumInsertionSort.c -o InsertionSortedNum
word_insertion: WordInsertionSort.c
	gcc WordInsertionSort.c S_swap.c -o InsertionSortedWord
del_num_insertion: InsertionSortedNum
	rm -f InsertionSortedNum
del_word_insertion: InsertionSoertedWord
	rm -f InsertionSortedWord
