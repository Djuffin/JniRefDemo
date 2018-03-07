#ifndef JNIREFDEMO_LATIN_H
#define JNIREFDEMO_LATIN_H

template <class Callback>
class Latin {
    Callback body_;

public:
    Latin(Callback &body) : body_(body) {}

    __attribute__ ((noinline)) void I() {
        II();
    }

    __attribute__ ((noinline)) void II() {
        III();
    }

    __attribute__ ((noinline)) void III() {
        IV();
    }

    __attribute__ ((noinline)) void IV() {
        V();
    }

    __attribute__ ((noinline)) void V() {
        VI();
    }

    __attribute__ ((noinline)) void VI() {
        VII();
    }

    __attribute__ ((noinline)) void VII() {
        VIII();
    }

    __attribute__ ((noinline)) void VIII() {
        IX();
    }

    __attribute__ ((noinline)) void IX() {
        X();
    }

    __attribute__ ((noinline)) void X() {
        body_();
    };
};


#endif //JNIREFDEMO_LATIN_H
