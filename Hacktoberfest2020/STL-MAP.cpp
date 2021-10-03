int main (){
  map<char,int> github;
                              //initializing number with char map
  github['a']=10;
  github['b']=20;
  github['c']=30;
  github['d']=40;

   map<char, int>::iterator it;

   for(it = github.begin() ; it! = github.end() ; ++it){   //iterating through the map
      cout << it->first << " => " << it->second << '\n';
   }

  return 0;
}
