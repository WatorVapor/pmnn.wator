#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <numeric>
#include <iomanip>
#include <thread>
using namespace std;


#include "net.hpp"
#include "base_layer.hpp"


#define DUMP_VAR(x) {cout << __LINE__ << ":" #x "=<" << x << ">" << endl;}


WatorNet::WatorNet(WatorBaseLPtr entry)
  :entry_(entry) {
}
void WatorNet::train(void) {
    //entry_->forward();
}
void WatorNet::build(void) {
  entry_->build();
  auto bindOperation = std::bind(&WatorBaseL::operator(), entry_);
  std::thread t(bindOperation);
  t.join();
}

void WatorNet::snapshot(void) {
  entry_->snapshot();
}


