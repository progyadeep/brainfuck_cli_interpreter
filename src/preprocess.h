string preprocess(string s){
  string sp = "";
  for(int i=0; i<s.length(); i++){
    char c = s[i];
    //checking for invalid token:
    if(c!='+' && c!='-' && c!='<' && c!='>' && c!='.' && c!=',' && c!='[' && c!=']' && c!='#' && c!='$'){
      //end of story
      cout << "INVALID TOKEN \"" << c << "\" at index: " << i << endl;
      return "IT";
    }

    if(c != ' ')
      sp+=c;
  }
  return sp;
}
