#ifndef JNIREFDEMO_SPANISH_H
#define JNIREFDEMO_SPANISH_H
template <class Callback>
class Spanish {
    Callback body_;

public:
    Spanish(Callback &body) : body_(body) {}

    __attribute__ ((noinline)) void Uno() {
        Dos();
    }

    __attribute__ ((noinline)) void Dos() {
        Tres();
    }

    __attribute__ ((noinline)) void Tres() {
        Cuatro();
    }

    __attribute__ ((noinline)) void Cuatro() {
        Cinco();
    }

    __attribute__ ((noinline)) void Cinco() {
        Seis();
    }

    __attribute__ ((noinline)) void Seis() {
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
