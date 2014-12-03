#include "consoleui.h"

// User Interface
ConsoleUI::ConsoleUI()
{
    personService = PersonService();
}

// Fall sem keyrir user interfaceið, notað í main falli - forritið sjálft
void ConsoleUI::start()
{
    // köllum a fallið sem prentar logo
    verkurLogo();

    cout << "OMG. Welcome to this awesome program.\n" << endl;
    cout << "The program contains a list for you to maintain." << endl;
    cout << "The available commands are:" << endl;

    string inp;

    // Loopa sem promptar userinn um input, keyrir svo lengi sem ekki er gefið inn 'quit'
    while(inp != "quit" && inp != "exit" && inp != "q" && inp != "bail")
    {
        printComms();
        cout << ":";
        cin >> inp;

        // Add function
        if(inp == "add" || inp == "a")
        {
            add();
        }

        // Del function
        else if(inp == "del" || inp == "d")
        {
            del();
        }
        // List function
        else if(inp == "list" || inp == "l")
        {
            listi();
        }

        // Sort function
        else if(inp == "sort" || inp == "s")
        {
            sort();
        }

        // Find function
        else if(inp == "find" || inp == "f")
        {
            find();
        }

        // Quit function
        // Hoppað útúr while lykkju og forritið hættir keyrslu
        else if(inp == "quit" || inp == "exit" || inp == "q" || inp == "bail")
        {
            cout << "\nThank you very much for this program. Please come again.\n" << endl;
        }
        else
        {
            cout << "The command \'" << inp << "\' was not recognized." << endl;
            vector<string> params = countParam();
        }
    }
}

// Implement logo function
void ConsoleUI::verkurLogo()
{
    ifstream splash ("splash.txt");
    if(splash.is_open())
    {
        // LOGOið prentað út
        string currentLine;
        while(getline(splash, currentLine))
        {
            cout << currentLine << endl;
        }
        splash.close();
    }
}

// Implement add function
void ConsoleUI::add()
{
    // Bua til nyja personu

    // Fylla inn:
    string name;
    string sex;
    string years[2];
    int birth_year, death_year;

    // Lesum inn í breyturnar
    cout << "Name: ";
    cin.ignore(1000, '\n');
    getline(cin,name);
    cout << "Year of birth: ";
    cin >> years[0];
    cout << "Year of death (If alive, write 'alive'): ";
    cin >> years[1];

    // Breyta strengjum í int
    birth_year = atoi(years[0].c_str());
    death_year = atoi(years[1].c_str());

    // Error handling á user input á birth og death year
    while(birth_year > death_year && death_year != 0)
    {
        cout << "\nWhat a drag. It seems your character has died before being born." << endl;
        cout << "Please enter the information joyfully again." << endl;
        cout << "Year of birth: ";
        cin >> years[0];
        cout << "Year of death (If alive, write 'alive'): ";
        cin >> years[1];

        birth_year = atoi(years[0].c_str());
        death_year = atoi(years[1].c_str());
    }

    cout << "Sex: ";
    cin >> sex;

    // breyta Sex í uppercase (M/F)
    sex = str2upper(sex);

    // Error handling á input á kyni
    while(sex != "M" && sex != "F")
    {
        cout << "Alas, the sex is not right. Must be either M or F. Try again.\n";
        cout << "Sex: ";
        cin >> sex;
        // breyta kyninu í uppercase...
        sex = str2upper(sex);
    }

    bool add_exists = false;
    char add_answer = 'y';
    PersonContainer found = personService.find_p(name, add_exists);

    // Spyrjum notanda hvort hann vilji bæta við manneskju sem hefur verið bætt við áður
    if(add_exists)
    {
        cout << "A person with exactly the same name already exists.\n"
             << "Are you sure you want to add him/her anyway? (y/n) ";
        cin >> add_answer;
    }

    // Sýna notanda færsluna sem á að bæta við
    if(add_answer != 'n' && add_answer != 'N')
    {
        list(Person(name, birth_year, death_year, sex));
        cout << "Does this seem about right? (y/n) ";
        cin >> add_answer;
    }

    // Adda viðkomandi og senda skilaboð um að það hafi tekist, eða ef ekki
    if(add_answer == 'y' || add_answer == 'Y')
    {
        personService.add(Person(name, birth_year, death_year, sex));

        cout << "\nThank you for this wonderful addition to the database." << endl;
    }
    else
    {
        cout << "\nNothing was added. Praise the lord." << endl;
    }
}

// Implement del function
void ConsoleUI::del()
{
    // Birta lista yfir skrá með linunumeri og fa svo ad velja numer til ad eyda

    PersonContainer listed = personService.list();

    bool done = false;
    string id_input;

    vector<string> params = countParam();
    if(params.size() != 0)
    {
        done = true;
        id_input = params[0];
    }


    // Prompta user um id number ef done er false, annars er skrefinu sleppt
    if(!done)
    {
        // Prentaður út listi til að sjá númer
        list(listed);

        cout << "Enter no. of person you want to delete (confirmation later required): ";
        cin >> id_input;
    }

    bool canDel;

    // isValidInput athugar hvort id sé leyfilegt (innan marka), canDel verður þá true
    // og tekur strenginn id_input og kastar yfir í int og skilar því.
    int id = isValidInput(id_input, listed.size()+1, canDel);

    if(canDel)
    {
        // Birtum persónu sem user ætlar að fjarlægja úr listanum
        list(listed[id-1]);

        char answer;
        cout << "Are you most definitely sure you want to delete this person permanently? (y/n) ";
        cin >> answer;

        // Eyðum út persónu eftir staðfestingu
        if(answer == 'Y' || answer == 'y')
        {
            string delName = listed[id-1].getName();
            string delSex = listed[id-1].getSex();
            personService.del(id);
            cout << "\n" << delName << " was most gruesomely deleted from the database. Bless ";
                 if(delSex == "F"){ cout << "her." << endl;} else{cout << "him." << endl;}
        }
        else
        {
            cout << "\nNothing was deleted. Godspeed." << endl;
        }
    }
    else
    {
        cout << "\nThe input was not valid. Sorry (with a swedish accent)." << endl;
    }
}

// Implement list function
void ConsoleUI::listi()
{
    // Prumpa út listanum bara í heild sinni

    // Henda út parametrum sem koma á eftir
    vector<string> params = countParam();

    // Lata vita að list taki ekki við parametrum
    if(params.size() > 0)
    {
        cout << "The function 'list' does not use parameters." << endl;
    }

    PersonContainer listed = personService.list();
    list(listed);
}

// Implement sort function
void ConsoleUI::sort()
{
    string sort_inp;
    bool canSort;

    bool done = false;
    bool desc = false;

    vector<string> params = countParam();

    if(params.size() > 0)
    {
        done = true;
        sort_inp = params[0];

        if(params.size() > 1)
        {
            if(params[1] == "d")
                desc = true;
            else
                cout << "\'" << params[1] << "\' is not a known parameter for the sort function";
        }

        if(params.size() > 2 && params[1] != "d")
        {
            cout << " and only has 2 parameters.";
        }
        else if(params.size() > 2 && params[1] == "d")
        {
            cout << "The sort function only has 2 parameters";
        }
        else if(params.size() > 2)
        {
            cout << "." << endl;
        }
    }

    // Ef done er false þá er promptað um hvernig userinn vilji raða listanum
    if(!done)
    {
        cout << "What would you like to sort in the list? (Choose a number)" << endl;
        cout << "(1) Names\n(2) Year of birth\n(3) Year of death\n(4) Sex" << endl;
        // d fyrir descending
        cout << "Append with <space>d for descending (Ex: '3 d')";
        cout << ":";
        cin >> sort_inp;
    }

    // isValidInput athugar hvort id sé leyfilegt (innan marka), canDel verður þá true
    // og tekur strenginn id_input og kastar yfir í int og skilar því.
    int sort_after = isValidInput(sort_inp, 5, canSort);

    // Sortum listann á þann hátt sem userinn bað um
    if(canSort)
    {
        PersonContainer sorted = personService.sort_list(sort_after, desc);
        list(sorted);
    }
    else
    {
        cout << "\nThe option does not exist. Give it another shot.\n" << endl;
    }
}

//Implement find function
void ConsoleUI::find()
{
    bool exists = false;
    bool done = false;
    string search;

    // Öllu sem kom á eftir 'find' safnað saman í params vektorinn
    vector<string> params = countParam();

    // Tékkað hvort einhverjir parametrar voru
    // Í þessu tilfelli eru parametrarnir strengur og því öllu sem
    // á eftir 'find' kom safnað saman í strenginn 'search'
    if(params.size() > 0)
        {
            done = true;

            for(unsigned int i = 0; i < params.size(); i++)
            {
                search += params[i];
                if(i < params.size() - 1)
                {
                    search += " ";
                }
            }
        }

    // Ef einhverjir parametrar voru núþegar uppgefnir
    // þá þarf ekki að biðja um leitarstreng. done = true
    if(!done)
    {
        cout << "Enter a search string: " << endl;
        cin.ignore(1000, '\n');
        getline(cin,search);
    }

    // Búum til breytu af taginu PersonContainer og setjum þar leitarniðurstöðurnar
    // gildi bool breytunnar exists að ofan breytist eftir því hvort leitarstrengurinn
    // fannst eða ekki
    PersonContainer found = personService.find_p(search, exists);

    if(exists == false)
    {
        cout << "Search did not give any results." << endl;
    }
    else
    {
        cout << "\n\'" << search << "\' was found in " << found.size() << " entries:" << endl;
        list(found);
    }
}

// Fall sem prentar út lista eftir vektor sem er gefinn með mörgum persónum í
void list(PersonContainer listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "\nNo one in database!" << endl;
    }
    else
    {

        cout << "\n+-----------------------------------------------------+" << endl;
        cout << setw(3) << "No."
             << setw(37) << "Name"
             << setw(5) << "Born"
             << setw(5) << "Dead"
             << setw(5) << "Sex"
             << endl;
        cout << "+-----------------------------------------------------+" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << setw(3) << i+1
                 << setw(37) << listed[i].getName()
                 << setw(5) << listed[i].getBY()
                 << setw(5); if(listed[i].getDY() == 0){ cout << "-"; } else { cout << listed[i].getDY(); }
            cout << setw(5) << listed[i].getSex()
                 << endl;
        }
            cout << "+--------------------------END------------------------+\n" << endl;
     }
}

// Fall sem prentar út einstakling
void list(Person listed)
{
    cout << "\n+-----------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << setw(37) << "Name"
         << setw(5) << "Born"
         << setw(5) << "Dead"
         << setw(5) << "Sex"
         << endl;
    cout << "+-----------------------------------------------------+" << endl;

    cout << setw(3) << ""
         << setw(37) << listed.getName()
         << setw(5) << listed.getBY()
         << setw(5); if(listed.getDY() == 0){ cout << "-"; } else { cout << listed.getDY(); }
    cout << setw(5) << listed.getSex()
         << endl;

    cout << "+--------------------------END------------------------+\n" << endl;
}

// isValidInput athugar hvort id sé leyfilegt (innan marka), isOK verður þá true
// og tekur strenginn inp og kastar yfir í int og skilar því.
int isValidInput(const string& inp, const int& lessThan, bool& isOK)
{
    int result = atoi(inp.c_str());

    // cout << result << endl;

    if(result > 0 && result < lessThan)
    {
        isOK = true;
        return result;
    }
    else
    {
        isOK = false;
    }

    return -1;
}

void printComms()
{
    cout << "\n[add] [del] [list] [find] [sort] [quit]" << endl;
}

// Fall til að taka inn parametra og skila þeim í vektor af strengjum
vector<string> countParam()
{
    char nextin;
    vector<string> p;
    string param = "";

    cin.get(nextin);

    if(nextin == ' ' || nextin == '\t')
    {
        cin.get(nextin);

        while(nextin != '\n')
        {
            param = "";

            while(nextin == ' ' || nextin == '\t')
            {
                cin.get(nextin);
                if(nextin == '\n')
                {
                    cin.putback(nextin);
                    break;
                }
            }
            while(nextin != ' ' && nextin != '\t' && nextin != '\n')
            {
                param += nextin;
                cin.get(nextin);
                if(nextin == '\n')
                {
                    cin.putback(nextin);
                    break;
                }
            }
            p.push_back(param);
        }
    }
    else
    {
        cin.putback(nextin);
    }

    return p;
}
