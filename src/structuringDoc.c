/*
 * structuringDoc.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Carlos Miguens
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

int strCharCount(char *text, char *toCount, char *until)
{
	int n = 0;
	char *limit = strstr(text, until);
	if ((limit == NULL) || (strcmp(until, "\0") == 0))
		limit = text + strlen(text) - 1;
	while ((text != NULL) && (text < limit))
	{
		text = strstr(text, toCount);
		if (text != NULL) text++;
		n++;
	}
	return n;
}

void assignWord(struct word *words, char *start, char *limit)
{
	int n = 0;

	while ((start != NULL) && (start < limit))
	{
		char *wordend = strstr(start, " ");
		if ((wordend == NULL) || (wordend > strstr(start, ".")))
			wordend = strstr(start, ".");
		int wordlen = abs(start - wordend);
		words[n].data = malloc(sizeof(char) * wordlen);
		strncpy(words[n].data, start, wordlen);
		words[n].data[wordlen] = '\0';
		start = strstr(start, " ");
		if (start != NULL)
		{
			start++;
			n++;
		}
	}
}


struct document get_document(char* text) {
	struct document doc = {};
	doc.paragraph_count = strCharCount(text, "\n", "\0");
	doc.data = malloc(sizeof(struct paragraph) * doc.paragraph_count);

	char *pstart = text;
	char *pend = strstr(text, "\n");
	char *senstart = pstart;
	char *senend;

	for (int nP = 0; nP < doc.paragraph_count; nP++)
	{
		struct paragraph *par = &doc.data[nP];
		par->sentence_count = strCharCount(pstart, ".", "\n");
		par->data = malloc(sizeof(struct sentence) * par->sentence_count);
		senstart = pstart;

		for(int nS = 0; nS < par->sentence_count; nS++)
		{
			struct sentence *sen = &par->data[nS];
			senend = strstr(senstart, ".");
			sen->word_count = strCharCount(senstart, " ", ".");
			sen->data = malloc(sizeof(struct word) * sen->word_count);
			assignWord(sen->data, senstart, senend);

			senstart = senend + 1;
			while ((*senstart == ' ') && (*senstart != '.') && (*senstart != '\n') && (*senstart != '\0'))
				senstart++;
			senend = strstr(senstart, ".");
		}
		if (pend != NULL)
		{
			pstart = pend + 1;
			pend = strstr(pstart, "\n");
		}
	}


	return doc;
}
int sw = 0;

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	struct word w;
	if (Doc.paragraph_count > k)
		w = Doc.data[k-1].data[m-1].data[n-1];
	else {
		w = Doc.data[n-1].data[m-1].data[k-1];
		sw = 1;
	}
	return w;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
	struct sentence s = Doc.data[k-1].data[m-1];
	if (sw == 1)
		s = Doc.data[m-1].data[k-1];
	return s;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	struct paragraph p = Doc.data[k-1];
	return p;
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main31()
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}
