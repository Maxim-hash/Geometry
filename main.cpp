#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>

using namespace sf;
using namespace std;

typedef int c_characters[3];

int Count(string enter)
{
    int counter = 0;
    int temp = enter.find("circle(");
    while (temp >= 0) {
            
            counter++;
            int p = enter.find_first_of("(");
            enter.erase(0, p + 1);
            string c = "";
            c.append(enter.substr(0, 1));
            enter.erase(0, 1);

            int f = c.find_first_of(")");

            while (f < 0) {
                c.append(enter.substr(0, 1));
                enter.erase(0, 1);
                f = c.find_first_of(")");
            }
            int comma = c.find_first_of(",");

            c.erase(f);

            f = c.find_first_of(" ");
            temp = enter.find("circle(");
            
        }
        return counter;
}

int main()
{
    string enter;
    getline(cin, enter);
    int x, y, r, i = 0;
    c_characters* mas;
    int razmer = Count(enter);
    int temp = enter.find("circle(");
    mas = new c_characters[razmer];


    RenderWindow window(VideoMode(1920, 1080), "SFML works!" , Style::Fullscreen);
    CircleShape circle1;

    while (razmer - i > 0) {
            

            
            int p = enter.find_first_of("(");
            enter.erase(0, p + 1);
            string c = "";
            c.append(enter.substr(0, 1));
            enter.erase(0, 1);

            int f = c.find_first_of(")");

            while (f < 0) {
                c.append(enter.substr(0, 1));
                enter.erase(0, 1);
                f = c.find_first_of(")");
            }
            int comma = c.find_first_of(",");

            c.erase(f);

            f = c.find_first_of(" ");

            string xstr = "";
            string ystr = "";
            string rstr = "";
            rstr.append(c.substr(comma + 1));
            xstr.append(c.substr(0, f));
            ystr.append(c.substr(f + 1, comma));
            
            r = atoi(rstr.c_str());
            x = atoi(xstr.c_str());
            y = atoi(ystr.c_str());
     
            
            mas[i][0] = x;
            mas[i][1] = y;
            mas[i][2] = r;      
            i++;

            temp = enter.find("circle(");
        }
        for(int u = 0; u < i; u++)
    {
        
        double per, sq;
        per = 2 * mas[u][2] * 3.1415;
        sq = 3.1415 * mas[u][2] * mas[u][2];
        cout << u+1 << " krug  x = "   << mas[u][0]<< " y = " << mas[u][1]<< endl;
        cout << "Perimetr = " << per << endl;
        cout << "Ploshad' = " << sq << endl;
        for(int g = 0; g < i; g++)
        {
            int rast, sumR;
            if(g == u)
                g++;
            if(g == i)
            break;
            rast = sqrt(pow(mas[u][0] - mas[g][0] , 2) + pow(mas[u][1] - mas[g][1] , 2));
            sumR = mas[u][2] + mas[g][2];
            if(rast <= sumR)
            {
                cout << "Peresekaetsya s " << g + 1 << " Krugom" << endl;
            }
            else
            {
                cout << "Ne peresekaetsya s " << g + 1 << " Krugom" << endl;
            }

        }
        cout << endl << endl;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        
        for(int u = 0; u < razmer; u++)
        {
            circle1.setRadius((float)mas[u][2]);
            circle1.setPosition((float)mas[u][0],(float)mas[u][1]);
            circle1.setFillColor(Color(mas[u][0] % 256, mas[u][1] % 256, mas[u][2] % 256));
            circle1.setPointCount(mas[u][2] * mas[u][2]);
            
            
            
            window.draw(circle1);
        }
        window.display();   
    }
    
    return 0;
}
