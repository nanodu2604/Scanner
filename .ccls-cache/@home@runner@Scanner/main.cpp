#include <iostream>
#include <unordered_map>
#include <regex>
#include <vector>
#include <string>

std::unordered_map<std::string,int> token_table(std::string str){
  std::regex regex("\\s+"); // Matches one or more spaces
  std::sregex_token_iterator iter(str.begin(), str.end(), regex, -1);
  std::sregex_token_iterator end;
  std::regex regex2("\\d+\\.\\d+"); // Matches one or more digits
  std::regex regex3("\\w+\\="); //Mathes keyword for variable 
  std::vector<std::string> tokens(iter, end);
  int IF_ID=0;
  int NUM_ID=1;
  int OPERATOR_ID=2;
  int IDENTIFIER_ID=3;
  std::unordered_map<std::string,int> token_table;
  for(std::string token:tokens){
    if(token=="if"||token=="else"){
      token_table[token]=IF_ID;
    }else if(token=="+"||token=="-"||token=="*"||token=="/"){
      token_table[token]=OPERATOR_ID;
    }else if(std::regex_match(token,regex3)){
      token_table[token]=IDENTIFIER_ID;
    }else if(std::regex_match(token,regex2)){
      token_table[token]=NUM_ID;
    }
  }
  return token_table;
} 

int count=0;
std::vector<std::string> token_list;
std::string gettoken(){
  std::string str;
  //std::vector<std::string> token_list={"IF","NUM","OPERATOR","IDENTIFIER"};
  //itterate whenever call x times this function
  if(count<token_list.size()){
    return token_list[count++];
  }else{
    return "";
  }
}
int main() { 
  std::string str;
  std::getline(std::cin, str);
  token_list.clear();
  std::unordered_map<std::string,int> tokens=token_table(str);
  for (const auto& entry : tokens) {
      token_list.push_back(entry.first);  // Store tokens in order
  }
  std::cout << gettoken();
  return 0;
}