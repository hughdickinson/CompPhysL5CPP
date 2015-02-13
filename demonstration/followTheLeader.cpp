#include <iostream>
#include <string>

class Base {

  std::string name;
  
public :

  Base():
    name("Spartacus")
  {}

  std::string getName(){
    return name;
  }

  void setName(const std::string & name){
    this->name = name;
  }
  
  void declare(){
    std::cout << "I'm " << getName() << "!" << std::endl;
  }
  
};

class Derived : public Base {

public :
  
  Derived()
  {}

  Derived(std::string & name)
  {
    setName(name);
  }
  
};

class ReDerived : public Derived {

  bool hasBravery;
  
public :
  
  ReDerived():
    hasBravery(true)
  {}

  ReDerived(const std::string & name):
    hasBravery(false)
  {
      setName(name);
  }

  void declare(){
    if(hasBravery){
      std::cout << "No! I'm " << getName() << "!" << std::endl;
    }
    else{
      std::cout << "I'm " << getName() << ". Pleased to meet you, general." << std::endl;
    }
  }

};



int main(int argc, char * argv[]){

  Base leader;
  Derived firstFollower;
  ReDerived secondFollower;
  ReDerived thirdFollower("Batiatus");

  leader.declare();
  firstFollower.declare();
  secondFollower.declare();
  thirdFollower.declare();
  
  return 0;
}
    
