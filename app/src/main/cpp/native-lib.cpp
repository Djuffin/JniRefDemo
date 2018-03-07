#include <jni.h>
#include <string>
#include <vector>
#include "Spanish.h"
#include "English.h"
#include "Latin.h"

static JavaVM* g_vm;

jlong NewRef(JNIEnv *env, jobject cls, jobject obj) {
    jlong result = 0;
    auto f = [env, obj, &result]() {
        result = reinterpret_cast<jlong>(env->NewGlobalRef(obj));
    };
    static int count = 0;
    switch (count++ % 3) {
        case 0: {
            Spanish<decltype(f)> callstack(f);
            callstack.Uno();
            break;

        }
        case 1: {
            English<decltype(f)> callstack(f);
            callstack.One();
            break;
        }
        case 2: {
            Latin<decltype(f)> callstack(f);
            callstack.I();
            break;
        }
    }
    return result;
}

void ReleaseRef(JNIEnv *env, jobject cls, jlong ref) {
    auto f = [env, ref]() {
        env->DeleteGlobalRef(reinterpret_cast<jobject>(ref));
    };
    static int count = 0;
    switch (count++ % 3) {
        case 0: {
            Spanish<decltype(f)> callstack(f);
            callstack.Uno();
            break;

        }
        case 1: {
            English<decltype(f)> callstack(f);
            callstack.One();
            break;
        }
        case 2: {
            Latin<decltype(f)> callstack(f);
            callstack.I();
            break;
        }
    }

}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* vm, void* reserved) {
    g_vm = vm;
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    std::vector<JNINativeMethod> methods {
            {"NewRef",    "(Ljava/lang/Object;)J",   (void *)&NewRef},
            {"ReleaseRef",    "(J)V",   (void *)&ReleaseRef},
    };

    jclass cls = env->FindClass("com/google/jnirefdemo/Interop");
    env->RegisterNatives(cls, methods.data(), methods.size());

    return JNI_VERSION_1_6;
}