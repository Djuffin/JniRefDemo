package com.google.jnirefdemo;

public class Interop {
    public native static long NewRef(Object o);
    public native static void ReleaseRef(long ref);
}
