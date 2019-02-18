string preprocess(string s){
  string sp = "";
  for(int i=0; i<s.length(); i++){
    if(s[i] != ' ')
      sp+=s[i];
  }
  return sp;
}
