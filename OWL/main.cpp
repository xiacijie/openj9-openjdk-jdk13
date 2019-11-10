#include "../omr/compiler/optimizer/OWLTypes.hpp"
#include "../omr/compiler/optimizer/OWLAnalyser.hpp"
#include "../omr/compiler/optimizer/OWLJNIClient.hpp"
#include "../omr/compiler/optimizer/OWLShrikeBTConstructor.hpp"
#include "../omr/compiler/optimizer/OWLDeserializer.hpp"
#include <vector>

using namespace std;
int main(){

    TR_OWLJNIClient *jniClient = new TR_OWLJNIClient();
    if (jniClient->startJVM()){

        vector<OWLInstruction> owlInstructions = deserialize();
        TR_OWLShrikeBTConstructor* constructor = new TR_OWLShrikeBTConstructor(jniClient);
        vector<jobject> shrikeBTInstructions = constructor->constructShrikeBTInstructions(owlInstructions);
        TR_OWLAnalyser * ana = new TR_OWLAnalyser(jniClient);
        ana->analyse(shrikeBTInstructions);
        delete jniClient;
    }
    else{
        printf("JVM cannot be start!\n");
    }
    return 0;
}
