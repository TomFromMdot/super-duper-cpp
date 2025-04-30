

/*
 *
 * First we need interefaces for states...
 *
 * */

#include <iostream>
#include <vector>
enum class States
{
  INIT,
  UPDATE,
  RENDER,
};
class IState
{
public:
  virtual void useState(States currentState) = 0;
};

class UpdateState : public virtual IState
{
protected:
  virtual void updateState() = 0;
};

class InitState : public virtual IState
{
protected:
  virtual void initState() = 0;
};

class RenderState : public virtual IState
{
protected:
  virtual void renderState() = 0;
};

class GameObject : public virtual InitState,
                   virtual UpdateState,
                   virtual RenderState
{
protected:
  bool isLoaded = false;

public:
  virtual void useState(States currentState) override
  {
    switch (currentState)
    {
    case States::INIT:
    {
      if (!isLoaded)
      {
        initState();
        isLoaded = true;
      }
      break;
    }
    case States::UPDATE:
    {
      updateState();
      break;
    }
    case States::RENDER:
    {
      renderState();
      break;
    }
    }
  }
};

class Player : public GameObject
{
public:
  Player() {}
  ~Player() {}

private:
  virtual void initState() override
  {
    std::cout << "load something to memory and build all GameObject\n";
  }
  virtual void updateState() override
  {
    std::cout << "update position or something\n";
  }
  virtual void renderState() override
  {
    std::cout << "Render state here u can render something\n";
  }
};

int main()
{

  /*
   * Simple test
   * U can use any states in diferent loops...*/
  std::vector<GameObject *> gameobjects;
  Player *p = new Player();

  gameobjects.push_back(p);

  for (auto i = 0; i < 5; ++i)
  {
    for (auto &obj : gameobjects)
    {
      obj->useState(States::INIT);
      obj->useState(States::UPDATE);
      obj->useState(States::RENDER);
    }
  }

  return 0;
}
