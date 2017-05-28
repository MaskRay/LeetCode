struct LogSystem{
  map<int,string>a;
  void put(int i,string t){a[i]=t;}
  vector<int>retrieve(string s,string e,string g){
    int i=string("YMDHMS").find(g[0]);g[1]=='i'?i=4:0;
    for(s=s.substr(0,4+3*i),e=e.substr(0,4+3*i);i++<5;s+=":00",e+=":99");
    vector<int>r;
    for(auto&x:a)
      if(s<=(g=x.second)&&g<=e)
        r.push_back(x.first);
    return r;
  }
};
