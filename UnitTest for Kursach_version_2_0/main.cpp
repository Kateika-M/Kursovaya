#include <UnitTest++/UnitTest++.h>
#include </home/katya/Documents/GitHub/Kursovaya/Kursach_version_2.0/PseudorandomGenerator.cpp>

struct PseudorandomGenerator_fixture {
    PseudorandomGenerator * object;
    PseudorandomGenerator_fixture() {
        object = new PseudorandomGenerator();
        vector<uint64_t> reg_all = {1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,1};
        object->setReg(reg_all);
    }
    ~PseudorandomGenerator_fixture() {
        delete object;
    }
};

SUITE(KeyTest)
{
    vector<uint64_t> reg1 = {1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,1};//регистр верный
    TEST_FIXTURE(PseudorandomGenerator_fixture, Correctline){
        object->setReg(reg1);
                CHECK(true);
    }
    vector<uint64_t> reg2 = {1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,1};//длиннее 48 символов
    TEST_FIXTURE(PseudorandomGenerator_fixture, dontcorrectline){
                CHECK_THROW(object->setReg(reg2), PseudorandomGeneratorError);
    }
    vector<uint64_t> reg3 = {1,1,0};//короче 48 символов
    TEST_FIXTURE(PseudorandomGenerator_fixture, dontcorrectline2){
                CHECK_THROW(object->setReg(reg3), PseudorandomGeneratorError);
    }
    vector<uint64_t> reg4 = {};//пустая строка
    TEST_FIXTURE(PseudorandomGenerator_fixture, pystline){
                CHECK_THROW(object->setReg(reg4), PseudorandomGeneratorError);
    }
    vector<uint64_t> reg5 = {9,1,0,1,6,8,1,0,7,1,0,1,1,7,1,0,0,4,1,0,9,5,1,1,1,1,3,3,3,3,1,0,5,1,0,1,1,1,1,0,0,5,1,0,5,5,1,1};//введены не только 0 и 1
    TEST_FIXTURE(PseudorandomGenerator_fixture, InvalidSymbols){
                CHECK_THROW(object->setReg(reg5), PseudorandomGeneratorError);
    }
    vector<uint64_t> reg6 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//если введены все 0
    TEST_FIXTURE(PseudorandomGenerator_fixture, Zeroline){
                CHECK_THROW(object->setReg(reg6), PseudorandomGeneratorError);
    }


}


SUITE(GenerateTest) {
    TEST_FIXTURE(PseudorandomGenerator_fixture, linpos){//проверка битности
        object->gen(12);
                CHECK(true);
    }
    TEST_FIXTURE(PseudorandomGenerator_fixture, necevbitchisel){//неверная битность числа
                CHECK_THROW(object->gen(49), PseudorandomGeneratorError);
    }
    TEST_FIXTURE(PseudorandomGenerator_fixture, otricdlinaibitchisel){//отрицательная битность числа
                CHECK_THROW(object->gen(-12), PseudorandomGeneratorError);
    }
    TEST_FIXTURE(PseudorandomGenerator_fixture, Zerolinpos){//нулевая битность числа
                CHECK_THROW(object->gen(0), PseudorandomGeneratorError);
    }
}
int main(int argc, char **argv) {
    return UnitTest::RunAllTests();
}