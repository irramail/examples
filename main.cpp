#include <map>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

std::vector<std::pair<std::string, std::string> > load_map_weight() {
  std::string weight;
  std::vector<std::pair<std::string, std::string> > result;
  std::ifstream ifweight;
  ifweight.open("weight.rm");
  while(ifweight.good()) {
    std::getline(ifweight, weight);
    if (weight.length() > 0) {
      result.push_back(std::pair<std::string, std::string>(weight.substr(0, weight.find('|')), weight.substr(weight.find('|') + 1) ));
    }
  }
  ifweight.close();

  return result;
}

int main() {
  std::multimap<std::string, std::string> mymap;

  std::vector<std::pair<std::string, std::string> > lmw;
  lmw = load_map_weight();

  for(unsigned int i=0; i < lmw.size(); i++ ) {
    mymap.insert(lmw[i]);
  }

  std::multimap<std::string, std::string>::iterator it = mymap.begin();

  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  do {

  for(  std::multimap<std::string, std::string>::iterator it = mymap.begin(); it != mymap.end(); it = mymap.upper_bound(it->first))
  {
      std::cout << it->first << std::endl;
      std::pair <std::multimap<std::string, std::string>::iterator, std::multimap<std::string,std::string>::iterator> ret;
      ret = mymap.equal_range(it->first);

      for (std::multimap<std::string, std::string>::iterator it=ret.first; it!=ret.second; ++it) {
        std::cout << ' ' << it->second;
        mymap.erase(it);
        break;
      }
      std::cout << std::endl;


  }
  std::cout << mymap.size() << std::endl;
  }
  while(mymap.size());

  return 0;
}
