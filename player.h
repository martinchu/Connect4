class Player{
public:
  virtual void checkHuman() = 0; //Testing Purpose;
  virtual void makeMove() = 0;
};
class Human: public Player{
public:
  void checkHuman();
  void makeMove();
};
class AI: public Player{
public:
  void checkHuman();
  void makeMove();
};
