#include <jni.h>
#include <string>
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include <bitset>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testgoso_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    void *handle = dlopen("lib4Android.so", RTLD_LAZY);
    long (*TestGetAccountBalance)();
    /*根据动态链接库操作句柄与符号，返回符号对应的地址*/
    TestGetAccountBalance = (long (*)()) dlsym(handle, "TestGetAccountBalance");

    long result = TestGetAccountBalance();
    char str[100];
    sprintf(str, "%ld", result);
    return env->NewStringUTF(str);
}
