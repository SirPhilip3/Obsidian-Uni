---
publish: true
---
**BERT ( Bidirectional Encoder Representations for Transformers )** 

In [[Learning to Rank#Skip-Gram Model ( Word2vec )|Word2vec]] we use *static word embeddings* , these embeddings will fail with multi-sense terms and end up with sense averaged representation

*Contextualized word embeddings* allow for local representation of words depending on other words used together 

## Before Transformers

+ **Recurrent neural networks** ( *RNN* )
	Used for language understanding tasks

Given an input sequence of terms produce an output sequence of transalted terms , sequentially left to right
## Transformers

Transformer are based on *Encoders* and *Decoders* 

The **Transformer** applies *self-attention* mechanism that directly models relationships between all words in a sentence independently of their position ( no more left-to-right )

#todo 

## Pre-Trained Language Models

A significant advantage is the use of *semi-supervision* in *pretraining* 

We can use *pretrained* models to perform further *fine-tuning* with *task-specific labeled data* 

**GPT** ( *Generative Pre-Training* models ) are *decoder-only transformer* 
## Bidirectional Encoder Representations from Transformers (BERT)

*BERT* can be viewed as an *encoder-only* transformer, applied to document ranking

*Masked Language Model* ( *MLM* ) randomly cover up a token from the input sequence and ask the model to guess it

*Next sentence prediction* : given two sentences learn to predict if the second sentence is the subsequente sentence in the original document 

### Transfer learning

We modify the last layer of the language model with a *classifier* after *BERT* , training it on a specific task with a labeled dataset

### Tokenizer

*WordPiece* tokenizer : 
	Uses \#\# to indicate that a subword is present in the vocabulary 

>[!example] 
>"scrolling" becomes "scroll"+"##ing"

*BPE* tokenizer
### BERT tasks

*BERT* converts a sequence of input emebeddings into a sequence of contextual embeddings 

>[!note] Other tasks
>+ *Single-input classification* :
>	Sentiment analysis on a single text segment
>+ *Two-input classification* :
>	Are two sentences paraphrases of one another ?
>+ *Single-input token labeling* :
>	named-entity recognition , label assigned to each token

### Fine-tuning BERT

Given a *query-document pair* both texts are tokenized into token sequence , they are concatenated with *BERT* special tokens :
+ $[CLS]$ : start token
+ $[SEP]$ : separator token 

Then *BERT* is fine tuned with a binary classification task to comput the query-document relevance score $\{0,1\}$ 

#todo 