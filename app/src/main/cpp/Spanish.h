#ifndef JNIREFDEMO_SPANISH_H
#define JNIREFDEMO_SPANISH_H
template <class Callback>
class Spanish {
    Callback body_;

public:
    Spanish(Callback &body) : body_(body) {}

    __attribute__ ((noinline)) void Uno() {
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
        Siete();
    }

    __attribute__ ((noinline)) void Siete() {
        Ocho();
    }

    __attribute__ ((noinline)) void Ocho() {
        Nueve();
    }

    __attribute__ ((noinline)) void Nueve() {
        Diez();
    }

    __attribute__ ((noinline)) void Diez() {
        body_();
    };
};

#endif //JNIREFDEMO_SPANISH_H
