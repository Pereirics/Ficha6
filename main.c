#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Exemplo

typedef struct staticStack {
    int sp;
    int values [MAX];
} STACK, *SStack;


void SinitStack(SStack s) {
    s->sp = 0;
}

int SisEmpty (SStack s){
    return (s->sp==0);
}

int Spush (SStack s, int x) {
    if (s->sp < MAX) {
        s->values[s->sp] = x;
        s->sp++;
        return 0;
    }
    return 1;
}

int Spop (SStack s, int *x) {
    if (SisEmpty(s) == 1) {
        *x = s->values[s->sp - 1];
        s->sp--;
        return 0;
    }
    return 1;
}

int Stop (SStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp-1];
        return 0;
    }
    return 1;
}

typedef struct staticQueue {
    int front;
    int length;
    int values [MAX];
} QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q->length = 0;
    q->front = 0;
}

int SisEmptyQ (SQueue q) {
    return (q->length == 0);
}

int Senqueue (SQueue q, int x) {
    if (q->length < MAX) {
        q->values[q->length++] = x;
        return 0;
    }
    return 1;
}

int Sdequeue (SQueue q, int *x) {
    if (q->length >= 0) {
        *x = q->values[q->front];
        q->front++;
        q->length--;
        return 0;
    }
    return 1;
}

int Sfront (SQueue q, int *x) {
    if (q->length >= 0) {
        *x = q->values[q->front];
        return 0;
    }
    return 1;
}

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

void DinitStack (DStack s) {
    s->sp = 0;
    s->size = 0;
    s->values = malloc(sizeof(int)*s->size);
}

int DisEmpty (DStack s) {
    return (s->size == 0);
}

int dupStack (DStack s) {
    int* temp = malloc(sizeof(int) * 2 * s->size);
    if (temp != NULL) {
        for (int i = 0; i < s->size; i++) {
            temp[i] = s->values[i];
        }
        free(s->values);
        s->values = temp;
        s->size *= 2;
        return 0;
    }
    return 1;
}

int Dpush (DStack s, int x) {
    int r = 0;
    if (s->sp < s->size) {
        s->values[s->sp++] = x;
    }
    else {
        r = dupStack(s);
        if (r == 0) {
            s->values[s->sp++] = x;
        }
    }
    return r;
}

int Dpop (DStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp--];
        return 0;
    }
    return 1;
}

int Dtop (DStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp-1];
        return 0;
    }
    return 1;
}




































