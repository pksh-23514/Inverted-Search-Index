# Inverted-Search-Index

## Abstract:
An inverted index is an index data structure storing a mapping from content, such as words or
numbers, to its locations in a database file, or in a document or a set of documents. The purpose of
an inverted index is to allow fast full text searches, at the cost of increased processing when a
document is added to the database. The inverted file may be the database file itself, rather than its
index. It is the most popular data structure used in document retrieval systems, used on a large
scale for example in search engines.

## Description:
### Forward Indexing - It is a data structure that stores mapping from documents to words i.e. directs you from document to word.<br>
#### Eg. - Table of contents in book.<br>
![image](https://user-images.githubusercontent.com/108017134/197331100-a767a4fd-2642-4866-830b-35185d326a45.png)
### Inverted Indexing - It is a data structure that stores mapping from words to documents or set of documents i.e. directs you from word to document.<br>
#### Eg. - Index at the back of the book.<br>
![image](https://user-images.githubusercontent.com/108017134/197331045-503ad98b-012f-48a3-b818-4ceb5c76ac97.png)

## Requirement Specification
Implementing this search program mainly consists two important functions.
1. Indexing
2. Querying

### Indexing:
By Indexing, we are creating a database file which contains the index of all words. So this can be
termed as Database Creation also. All the files whose index are to be created are selected and
inputed to this function. All the files are parsed and words are separated and indexed. They are
arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words
and the related file details. The index thus created is then stored in the file as database. This file is
later used in Querying. While the files are removed or added this index file is updated.<br>
![image](https://user-images.githubusercontent.com/108017134/197331303-61f55a28-7208-4782-a6cb-55603beeb985.png)
### Searching:
Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed
which is parsed into words and those words are searched in the index file. To avoid the overhead of
reading the file again, the file is converted back to a linkedList or hashing program, in which the
words are searched. The information about the files which contain the words are collected. The ones with 
more matches are filtered and produced as the result.<br>
![image](https://user-images.githubusercontent.com/108017134/197331344-ca1d158f-07a1-4759-9058-e58575e98a4c.png)

## Operations:
1. Create Database
2. Display Database
3. Search Database
4. Update Database
5. Save Database

## Printing Pattern:
Display the index number and details as follows -> [index_no] <word> <file_count> <filename> <word_count>

## Saving Pattern:
Store the contents in given pattern:<br>
1. #<index_no>;<br>
2. <word>;<file_count>;<file_name>;<word_count>#

## References:
1. https://en.wikipedia.org/wiki/Inverted_index
2. https://nlp.stanford.edu/IR-book/html/htmledition/a-first-take-at-building-an-inverted-index-1.html
3. https://www.ijcsi.org/papers/IJCSI-8-4-1-384-392.pdf
4. https://www.elastic.co/guide/en/elasticsearch/guide/current/inverted-index.html
