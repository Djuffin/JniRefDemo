#ifndef JNIREFDEMO_ENGLISH_H
#define JNIREFDEMO_ENGLISH_H
template <class Callback>
class English {
    Callback body_;

public:
    English(Callback &body) : body_(body) {}

    __attribute__ ((noinline)) void One() {
        Two();
    }

    __attribute__ ((noinline)) void Two() {
        Three();
    }

    __attribute__ ((noinline)) void Three() {
        Four();
    }

    __attribute__ ((noinline)) void Four() {
        Five();
    }

    __attribute__ ((noinline)) void Five() {
        Six();
    }

    __attribute__ ((noinline)) void Six() {
        Seven();
    }

    __attribute__ ((noinline)) void Seven() {
        Eight();
    }

    __attribute__ ((noinline)) void Eight() {
        Nine();
    }

    __attribute__ ((noinline)) void Nine() {
        Ten();
    }

    __attribute__ ((noinline)) void Ten() {
        body_();
    }
};

#endif //JNIREFDEMO_ENGLISH_H
