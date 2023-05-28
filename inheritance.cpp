#include <iostream>
#include <vector>

using namespace std;

int agentCount = 0;

class BaseAgent{
public:
  int id;
  string name;
  //  int vecPos;

  BaseAgent(){
    this->name = "defaultName";
    //    agentCount++;
    //    this->id = agentCount;

  }

  BaseAgent(string agentName, vector<BaseAgent>& vec){
    this->name = agentName;	
    //    agentCount++;
    //    this->id = agentCount;
    //    this->vecPos = agentCount-1;

    //    vec.push_back(*this);
  }
};

class Enemy: public BaseAgent{
public:
  bool alive;
  int health;
  int attack;

  
  Enemy(string enemyName, int enemyHealth, int enemyAttack, vector<Enemy>& vec){
    alive = true;
    this->name = enemyName;
    this->health = enemyHealth;
    this->attack = enemyAttack;
    
    agentCount++;
    this->id = agentCount;

    //this->vecPos = agentCount - 1;
    vec.push_back(*this);
    cout << "Enemy " << this->name << " was created\n";
    //    this->enemyVec = vec;
  }

  ~Enemy(){

  }

  
  void checkAlive(){
    if(this->health <= 0){
      cout << "The enemy " <<  this->name << " has died\n";
      alive = false;
    }
  }
};

 vector<BaseAgent> agentVec;
 vector<Enemy> enemyVec;
 

int main(){

  int agentSize = sizeof(agentVec)/sizeof(BaseAgent);  // vector holding all BaseAgents
  int enemySize = sizeof(enemyVec)/sizeof(Enemy);  // vector holding all Enemies

{
  //  BaseAgent agentA;
  /*
  BaseAgent agentB("steve", agentVec);
  BaseAgent agentC("adam", agentVec);
  BaseAgent agentD("stephanie", agentVec);
  BaseAgent agentE("brian", agentVec);
  */

    Enemy enemyA("warrior", 20, 10, enemyVec);
    Enemy enemyB("archer", 5, 15, enemyVec);
    Enemy enemyC("stabber",10, 15, enemyVec);
  //  Enemy* enemyA = new Enemy("warrior", 20, 10, enemyVec);
  //  Enemy* enemyB = new Enemy("archer", 5, 15, enemyVec);
  //  Enemy* enemyC = new Enemy("stabber", 10, 15, enemyVec);



    /*  cout << "BaseAgents: \n\n";
  for(BaseAgent& agent : agentVec){
    cout << "Name: " << agent.name << "\n";
    cout << "ID: " << agent.id << "\n";
    } */

  cout << "===================\n";
  
  cout << "Enemies: \n\n";
  for(Enemy& enemy : enemyVec){
    cout << "Name: " << enemy.name << "\n";
    cout << " ID: " << enemy.id << "\n";
    cout << " Health: " << enemy.health << "\n";
    cout << " Attack: " << enemy.attack << "\n";
    cout << " Alive?: " << enemy.alive << "\n";
  }
}

 cout << "========GAME========\n";
 for(int i = 0; i < 4; i++){

   cout << "Enemies: \n";
   cout << "--------------------\n";
   for(Enemy& enemy : enemyVec){
     if(enemy.alive == true){
     cout << "Name: " << enemy.name << "\n";
     cout << " ID: " << enemy.id << "\n";
     cout << " Health: " << enemy.health << "\n";
     cout << " Attack: " << enemy.attack << "\n";
     cout << " Alive?: " << enemy.alive << "\n";
     }
   }
   cout << "--------------------\n";   
   cout << "Damage round " << i+1 << " ( " <<  2*(i+1) << " points of damage):\n";
   for(Enemy& enemy : enemyVec){
     if(enemy.alive == true){
       
     enemy.health -= 2*(i+1);
     enemy.checkAlive();
     if(enemy.alive == false){
       cout << "++++++++++++++++++++\n";
       cout << "The fallen enemy is:\n";
       cout << "Name: " << enemy.name << "\n";
       cout << " ID: " << enemy.id << "\n";
       cout << " Health: " << enemy.health << "\n";
       cout << " Attack: " << enemy.attack << "\n";
       cout << " Alive?: " << enemy.alive << "\n";
       cout << "++++++++++++++++++++\n";
     }
     }
   }
   
 }
  return 0;
}
