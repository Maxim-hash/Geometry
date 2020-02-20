#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    string enter;
    getline(cin, enter);
    int x, y;
    
    int temp = enter.find("circle(");
    cout << temp << endl;
    if(temp >= 0)
    {
       int p = enter.find_first_of("(");
       enter.erase(0, p+1);
       string c = "";
        c.append(enter.substr(0, 1));
        enter.erase(0, 1);
        cout << c << " " << enter << endl;
       int f = c.find_first_of(")");

       while(f < 0)
       {
                c.append(enter.substr(0, 1));
                enter.erase(0, 1);
                cout << c << " " << enter << endl;
                f = c.find_first_of(")");
             
       } 
       c.erase(f);
       cout << c << endl;
       f = c.find_first_of(" ");
       cout << "[" << f << "]";
       string xstr = "";
       string ystr = "";
       xstr.append(c.substr(0, f));
       ystr.append(c.substr(f+1));
       cout << "xstr:" << xstr << "  ystr:" << ystr << endl;
       x = atoi(xstr.c_str());
       y = atoi(ystr.c_str());
    }
    else
    {
        int p = enter.find_first_of("(");
        enter.erase(p);
        cout << "Invalid shape '" << enter << "'";
    }
RenderWindow window(VideoMode(1280, 1080), "SFML works!");
    CircleShape circle1(200.f);
    circle1.setPosition(Vector2f(x, y));

    circle1.setFillColor(Color::Cyan);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle1);
        window.display();
    }

    return 0;
}