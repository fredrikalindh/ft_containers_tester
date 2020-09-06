TEST(StackTest, Constructor)
{
  LIBRARY::list<int> mylist(3, 100);     // deque with 3 elements
  LIBRARY::vector<int> myvector(2, 200); // vector with 2 elements

  LIBRARY::stack<int, LIBRARY::list<int> > first;          // empty stack
  LIBRARY::stack<int, LIBRARY::list<int> > second(mylist); // stack initialized to copy of deque

  LIBRARY::stack<int, LIBRARY::vector<int> > third; // empty stack using vector
  LIBRARY::stack<int, LIBRARY::vector<int> > fourth(myvector);
  EXPECT_EQ(first.size(), size_t(0));
  EXPECT_EQ(second.size(), size_t(3));
  EXPECT_EQ(third.size(), size_t(0));
  EXPECT_EQ(fourth.size(), size_t(2));
}

TEST(StackTest, Empty)
{
  LIBRARY::stack<int> mystack;
  int sum(0);

  for (int i = 1; i <= 10; i++)
    mystack.push(i);

  while (!mystack.empty())
  {
    sum += mystack.top();
    mystack.pop();
  }
  EXPECT_EQ(sum, 55);
}

TEST(StackTest, Push)
{
  LIBRARY::stack<int> mystack;

  for (int i = 0; i < 5; ++i)
    mystack.push(i);

  int i = 4;
  while (!mystack.empty())
  {
    EXPECT_EQ(mystack.top(), i--);
    mystack.pop();
  }
}

TEST(StackTest, Size)
{
  LIBRARY::stack<int> myints;
  EXPECT_EQ(myints.size(), size_t(0));
  for (int i = 0; i < 5; i++)
    myints.push(i);
  EXPECT_EQ(myints.size(), size_t(5));
  myints.pop();
  EXPECT_EQ(myints.size(), size_t(4));
}

TEST(StackTest, Top)
{
  LIBRARY::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  EXPECT_EQ(mystack.top(), 15);
}

TEST(StackTest, RelOp)
{
  LIBRARY::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);

  LIBRARY::stack<int, LIBRARY::list<int> > foo(a);
  LIBRARY::stack<int, LIBRARY::list<int> > bar(a);
  LIBRARY::stack<int, LIBRARY::list<int> > bob;
  bob.push(30);
  bob.push(20);
  bob.push(10);

  bar.push(0);

  EXPECT_FALSE(bob == bar);
  EXPECT_TRUE(bar != foo);
  EXPECT_TRUE(bar != bob);
  EXPECT_FALSE(foo > bar);
  EXPECT_TRUE(foo < bar);
  EXPECT_FALSE(foo >= bar);
  EXPECT_TRUE(foo <= bar);
}
