#include<vector>
#include<unordered_map>
#include<string>
std::string string_reader=""; 

std::string a;
std::unordered_map<std::string,int> token_table(std::string token){
  int IF_ID=0;
  int NUM_ID=1;
  int OPERATOR_ID=2;
  int IDENTIFIER_ID=3;
  std::unordered_map<std::string,int> token_table;
  std::vector<std::string> token_list={"IF","NUM","OPERATOR","IDENTIFIER"};
  if(token=="if"||token=="else"){
    token_table[token]=IF_ID;
  }else if(token=="+"||token=="-"||token=="*"||token=="/"){
    token_table[token]=OPERATOR_ID;
  }else if(token=="x"){
    token_table[token]=IDENTIFIER_ID;
  }
  return token_table;
}  


