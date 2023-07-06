# Description

An implementation of Huffman Coding.

It includes the following files:

- `heap.cpp` and `heap.h`: Implementation of the MinHeap data structure used in the Huffman coding algorithm.
- `huffman.cpp`: Implementation of the Huffman coding algorithm for text compression and decompression.
- `node.h`: Definition of the HuffmanTreeNode class representing a node in the Huffman tree.
- `pq.cpp` and `pq.h`: Implementation of the MinPriorityQueue data structure used in the Huffman coding algorithm.
- `test_pq.cpp`: Unit test file for the MinPriorityQueue class.

## Huffman Coding Algorithm

Huffman coding is a lossless data compression algorithm that assigns variable-length codes to different characters based on their frequencies of occurrence in the input text. It uses a binary tree, known as the Huffman tree, to generate the codes. The algorithm performs compression by replacing characters with their corresponding codes and decompression by traversing the Huffman tree.




