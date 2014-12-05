#include "consoleui.h"

// User Interface
ConsoleUI::ConsoleUI()
{
}

// Fall sem keyrir user interfaceið, notað í main falli - forritið sjálft
void ConsoleUI::start()
{
    // köllum a fallið sem prentar logo
    verkurLogo();

    cout << "OMG. Welcome to this awesome program.\n" << endl;
    cout << "The program contains two databases." << endl;
    cout << "One is a database of Programmers and the other one of Computers." << endl;
    cout << "It is possible to check out if the two are married." << endl;
    cout << endl;
    cout << "The available commands are:" << endl;

    string inp;

    // Loopa sem promptar userinn um input, keyrir svo lengi sem ekki er gefið inn 'quit' eða álíka
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
            list_c();
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
            cout << "And here I thought I knew everything. Dang." << endl;
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
    int pid = 0;
    string first_name, last_name;
    string sex;
    string nationality;
    string years[2];
    int birth_year, death_year;

    // Lesum inn í breyturnar
    // Allt strengir til að forritið beyglist ekki við
    // einhverjar kjánalegar innsetningar

    // add() hendir út öllu úr straumnum sem á eftir skipuninni kemur
    // og biður síðan gagngert aðeins um einn hlut í einu til að
    // inputtið sé örugglega rétt

    // Nafn getur verið hvað sem er og fyrstu stafir eru viljandi
    // ekki hækkaðir upp í uppercase
    // Dæmi: Ludwig van Beethoven, dr. Martin Luther King

    cout << "First Name: ";
    cin.ignore(1000, '\n');
    getline(cin, first_name);
    cout << "Last Name: ";
    getline(cin, last_name);
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

    cout << "Nationality: ";
    cin.ignore(1000, '\n');
    getline(cin, nationality);

    bool add_exists = false;
    char add_answer = 'y';
    string whole_name = first_name + " " + last_name;
    PersonContainer found = personService.find_p(whole_name, add_exists);

    // Spyrjum notanda hvort hann vilji bæta við manneskju sem hefur verið bætt við áður
    if(add_exists)
    {
        cout << "A person with exactly the same name already exists.\n"
             << "Are you sure you want to add him/her anyway? (y/n) ";
        cin >> add_answer;
        cin.ignore(1000, '\n');
    }

    // Sýna notanda færsluna sem á að bæta við
    if(add_answer != 'n' && add_answer != 'N')
    {
        show(Person(pid, first_name, last_name, birth_year, death_year, sex, nationality));
        cout << "Does this seem about right? (y/n) ";
        cin >> add_answer;
        cin.ignore(1000, '\n');
    }

    // Adda viðkomandi og senda skilaboð um að það hafi tekist, eða ef ekki
    if(add_answer == 'y' || add_answer == 'Y')
    {
        personService.add(Person(pid, first_name, last_name, birth_year, death_year, sex, nationality));

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

    PersonContainer listed;
    personService.list(listed);
    //CompContainer listed = personService.list(listed);

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
        show(listed);

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
        show(listed[id-1]);

        char answer;
        cout << "Are you most definitely sure you want to delete this person permanently? (y/n) ";
        cin >> answer;

        // Eyðum út persónu eftir staðfestingu
        if(answer == 'Y' || answer == 'y')
        {
            string delName = listed[id-1].getFName();
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
void ConsoleUI::list_c()
{
    // Prumpa út listanum bara í heild sinni

    // Gá hvort eitthvað var í straumnum á eftir 'list' skipuninni
    vector<string> params = countParam();

    // Tilgreina tóma containera svo þýðandinn fríki ekki út
    PersonContainer p;
    CompContainer c;
    string param;

    // Tékka á parametrum, soltið ruglingslegur kóði...
    if(params.size() == 0)
    {
        // Taka inn parameterinn
        cout << " Choose 'c' for a listing of Computers or " <<
        "'p' for a listing of Persons: ";
        cin >> param;

        // Taka inn restina. Þetta er bara til að hreinsa út strauminn og vita hvort
        // er að reyna að pumpa inn einhverjum óþarfa parametrum og láta
        // þá vita að það sé ekki í boði
        vector<string> nparams = countParam();

        // Bæta valinu inn í params og taka restina af
        // straumnum inn í params því kóðinn að neðan tékka
        params.push_back(param);
        for(unsigned int i = 0; i < nparams.size(); i++)
            params.push_back(nparams[i]);
    }


    // Geymi það að populata vektorana þangað til ég veit hvorn ég á að fylla
    // svona til að spara pláss. Hef hálfgerða óbeit á því að vera alltaf
    // að fylla þetta svona. Ha.
    // show fallið er svo overloadað til að taka annað hvort við PersonContainer
    // eða CompContainer. Þá lítur þetta allt frekar þægilega út og ekkert
    // aukalegt að muna
    if(params[0] == "p")
    {
        personService.list(p);
        show(p);
    }
    else if(params[0] == "c")
    {
        personService.list(c);
        show(c);
    }

    // Error handling með smá attitude
    else
    {
        cout << "The function 'list' does not use these funny parameters of yours." << endl;
    }

    if(params.size() > 1)
    {
        cout << "Perhaps try to tone down your use of parameters a little bit." << endl;
    }

}

// Implement sort function
void ConsoleUI::sort()
{
    string sort_inp;
    bool canSort;
    int sort_after;

    bool done = false;
    bool desc = false;

    vector<string> params = countParam();

    if(params.size() > 0)
    {
        done = true;
        sort_inp = params[0];

        // isValidInput athugar hvort id sé leyfilegt (innan marka), canDel verður þá true
        // og tekur strenginn id_input og kastar yfir í int og skilar því.
        sort_after = isValidInput(sort_inp, 5, canSort);

        if(canSort)
        {
            if(params.size() > 1)
            {
                if(params[1] == "d")
                {
                    desc = true;

                    if(params.size() > 2)
                        cout << "The sort function only has 2 parameters.";
                }
                else
                {
                    cout << "\'" << params[1] << "\' is not a known parameter for the sort function";

                    if(params.size() > 2 && params[1] != "d")
                        cout << " and only has 2 parameters";

                    cout << "." << endl;
                }
            }
        }
    }

    // Ef done er false þá er promptað um hvernig userinn vilji raða listanum
    if(!done)
    {
        cout << "What would you like to sort in the list? (Choose a number)" << endl;
        cout << "(1) Names\n"
             << "(2) Year of birth\n"
             << "(3) Year of death\n"
             << "(4) Sex"
             << endl;

        // d fyrir descending
        cout << "Append with <space>d for descending (Ex: '3 d')";
        cout << ":";
        cin >> sort_inp;

        // isValidInput athugar hvort id sé leyfilegt (innan marka), canDel verður þá true
        // og tekur strenginn id_input og kastar yfir í int og skilar því.
        sort_after = isValidInput(sort_inp, 5, canSort);

        vector<string> nextparams = countParam();

        if(canSort)
        {
            if(nextparams.size() >= 1)
            {
                if(nextparams[0] == "d")
                    desc = true;
                else
                {
                    cout << "\'" << nextparams[0] << "\' is not a paralegal." << endl;
                    cout << "...uhm sorry. I meant legal parameter." << endl;
                }
            }
        }
    }

    // Sortum listann á þann hátt sem userinn bað um
    if(canSort)
    {
        PersonContainer sorted = personService.sort_list(sort_after, desc);
        show(sorted);
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
        cout << "Enter a search string: ";
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
        show(found);
    }
}

// Fall sem prentar út lista eftir vektor sem er gefinn með mörgum persónum í
void show(PersonContainer listed)
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
            cout << listed[i];
        }
//        {
//            cout << setw(3) << i+1
//                 << setw(37) << listed[i].getFName() + " " + listed[i].getLName()
//                 << setw(5) << listed[i].getBY()
//                 << setw(5); if(listed[i].getDY() == 0){ cout << "-"; } else { cout << listed[i].getDY(); }
//            cout << setw(5) << listed[i].getSex()
//                 << endl;
//        }
           cout << "+--------------------------END------------------------+\n" << endl;
     }
}

void show(const CompContainer& listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "\nNo one in database!" << endl;
    }
    else
    {

        cout << "\n+------------------------------------------------------+" << endl;
        cout << setw(3) << "ID"
             << setw(27) << "Name"
             << setw(15) << "Type"
             << setw(5) << "Year"
             << setw(6) << "Built"
             << endl;
        cout << "+------------------------------------------------------+" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << listed[i];
//            cout << setw(3) << listed[i].getID()
//                 << setw(27) << listed[i].getName()
//                 << setw(15) << listed[i].getType()
//                 << setw(5)  << listed[i].getBuildYear();
//            cout << setw(6); (listed[i].getBuild())? cout << "Yes" : cout << "No";
//            cout << endl;
        }
            cout << "+---------------------------END------------------------+\n" << endl;
     }
}

// Fall sem prentar út einstakling
void show(Person listed)
{
    cout << "\n+-----------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << setw(37) << "Name"
         << setw(5) << "Born"
         << setw(5) << "Dead"
         << setw(5) << "Sex"
         << endl;
    cout << "+-----------------------------------------------------+" << endl;

    cout << listed;
//    cout << setw(3) << ""
//         << setw(37) << listed.getFName() << " " << listed.getLName()
//         << setw(5) << listed.getBY()
//         << setw(5); if(listed.getDY() == 0){ cout << "-"; } else { cout << listed.getDY(); }
//    cout << setw(5) << listed.getSex()
//         << endl;

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

// Prenta út mögulegar aðgerðir
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
