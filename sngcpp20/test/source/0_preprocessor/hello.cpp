#define STRINGIZE(x) #x
#define COMMA ", "
#define WORLD STRINGIZE(World)
#define HELLOWORLD STRINGIZE(Hello) COMMA WORLD
#define SAY(x) printf(x);

int main()
{
    SAY(HELLOWORLD)
}
