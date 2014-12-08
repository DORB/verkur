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

        // Relations function
        else if(inp == "rel" || inp == "r")
        {
            rel();
        }

        // Quit function
        // Hoppað útúr while lykkju og forritið hættir keyrslu
        else if(inp == "quit" || inp == "exit" || inp == "q" || inp == "bail")
        {
            cout << "\nThank you very much for this program. Please come again.\n" << endl;
        }
        else
        {
            cerr << "The command \'" << inp << "\' was not recognized." << endl;
            cerr << "And here I thought I knew everything. Dang." << endl;
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
    vector<string> params = countParam();
    string param;
    bool isPerson = true;

    // Ef ekkert var valið a eftir 'add' eða það var hvorki 'p' ne 'c'
    while(params.size() == 0 || (params[0] != "p" && params[0] != "c"))
    {
       // Taka inn parameterinn
       params.clear();
       cout << "Type 'c' to add to the Computers database " << endl;
       cout << "or 'p' to add to the Programmers database: ";
       cin >> param;
       params.push_back(param);
       trimParam(params, 1);
       vector<string> del = countParam();
    }

    if(params[0] == "p")
        isPerson = true;
    else
        isPerson = false;

    // Fylla inn:
    int pid = 0;
    string first_name, last_name, name;
    string sex;
    string nationality;
    string years[2];
    string type;
    int build_year;
    bool built;
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

    if(isPerson)
    {
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
            cerr << "\nWhat a drag. It seems your character has died before being born." << endl;
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
            cerr << "Alas, the sex is not right. Must be either M or F. Try again.\n";
            cout << "Sex: ";
            cin >> sex;
            // breyta kyninu í uppercase...
            sex = str2upper(sex);
        }

        cout << "Nationality: ";
        cin.ignore(1000, '\n');
        getline(cin, nationality);
    }
    // Ef fyrir tölvu
    else
    {
        cout << "Name: ";
        cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "Type: ";
        getline(cin, type);
        cout << "Build Year: ";
        cin >> years[0];
        cin.ignore(1000, '\n');
        do
        {
            cout << "Was it built? (y/n) ";
            cin >> param;
            param = str2lower(param);
            if(param == "y")
                built = true;
            else
                built = false;
        } while(param != "y" && param != "n");

        build_year = atoi(years[0].c_str());

    }

    bool add_exists = false;
    char add_answer = 'y';
    string whole_name;
    if(isPerson)
        whole_name = first_name + " " + last_name;
    else
        whole_name = name;

    PersonContainer found, temp;
    CompContainer c_found, c_temp;
    if(isPerson)
        found = service.find_p(whole_name, temp, add_exists);
    else
        c_found = service.find_p(whole_name, c_temp, add_exists);

    // Spyrjum notanda hvort hann vilji bæta við manneskju sem hefur verið bætt við áður
    if(add_exists)
    {
        cout << "\nAn entry with the same name already exists.\n"
             << "Are you sure you want to add it anyway? (y/n) ";
        cin >> add_answer;
        cin.ignore(1000, '\n');
    }

    // Sýna notanda færsluna sem á að bæta við
    if(add_answer != 'n' && add_answer != 'N')
    {
        if(isPerson)
            show(Person(pid, first_name, last_name, birth_year, death_year, sex, nationality));
        else
            show(Computer(0, name, type, build_year, built));

        cout << "Does this seem about right? (y/n) ";
        cin >> add_answer;
        cin.ignore(1000, '\n');
    }

    // Adda viðkomandi og senda skilaboð um að það hafi tekist, eða ef ekki
    if(add_answer == 'y' || add_answer == 'Y')
    {
        if(isPerson)
            service.add(Person(pid, first_name, last_name, birth_year, death_year, sex, nationality));
        else
            service.add(Computer(pid, name, type, build_year, built));

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
    vector<string> params = countParam();
    string param;

    PersonContainer p;
    CompContainer c;

    int listsize = 0, p_id, c_id;
    bool canDel = false;
    bool isPerson = true;


    // Ef ekkert var valið a eftir 'del' eða það var hvorki 'p' ne 'c'
    while(params.size() == 0 || (params[0] != "p" && params[0] != "c"))
    {
       // Taka inn parameterinn
       params.clear();
       cout << "Type 'c' to delete from the Computers database " << endl;
       cout << "or 'p' to delete from the Programmers database: ";
       cin >> param;
       params.push_back(param);
       trimParam(params, 1);
       vector<string> del = countParam();
    }

    if(params[0] == "p")
        isPerson = true;
    else
        isPerson = false;

    do
    {
        trimParam(params, 1);
        cout << "Type 'list' to see the list or 'search' to search for someone specific: ";
        cin >> param;

        if(param == "list")
            param = "l";
        else if(param == "search")
            param = "s";

        params.push_back(param);
        countParam(params);
        trimParam(params, 2);
    } while(params[1] != "s" && params[1] != "l");

    // Fyrir del með leit
    if(params[1] == "s")
    {
        bool search_successful = false;

        cout << "Enter search string: ";
        cin.ignore(1000, '\n');
        getline(cin, param);
        params.push_back(param);
        cout << "\nYour search string is: \'" << params[2] << "\'";
        if(isPerson)
        {
            service.search(params[2], p, search_successful);
            listsize = p.size();
            show(p);
        }
        else
        {
            service.search(params[2], c, search_successful);
            listsize = c.size();
            show(c);
        }

        // Ef bara einn er i listanum þarf bara staðfestingu
        if(listsize == 1)
        {
            do
            {
                trimParam(params, 3);
                cout << "Is this the correct entry to delete? (y/n) ";
                cin >> param;
                params.push_back(param);
                countParam(params);
                trimParam(params, 4);

                if(params[3] == "y")
                {
                    if(isPerson)
                        service.del(p[0]);
                    else
                        service.del(c[0]);
                    cout << "\nIt wasn't beautiful, but necessary." << endl;
                }
                else if(params[3] == "n" || params[3] == "N")
                {
                    search_successful = true;
                    cout << "\nNothing was deleted. Godspeed." << endl;
                }
            } while(params[3] != "y" && params[3] != "n");
        }

        // Ef fleiri eru i listanum er beðið um numerið a honum (i vektornum)
        else if(listsize > 1)
        {
            do
            {
                // Fa inn numerið a personu til að dela
                trimParam(params, 3);
                cout << "Type the no. of the entry to delete: ";
                cin >> param;
                params.push_back(param);
                countParam(params);
                trimParam(params, 4);

                isValidInput(param, listsize + 1, canDel);

                // Ef valið var innan rettra marka
                if(canDel)
                {
                    if(isPerson)
                    {
                        p_id = atoi(params[3].c_str()) - 1;
                        show(p[p_id]);
                    }
                    else
                    {
                        c_id = atoi(params[3].c_str()) - 1;
                        show(c[c_id]);
                    }

                    do
                    {
                        trimParam(params, 4);
                        if(isPerson)
                            cout << "\nHeavens, not " << p[p_id].getFName() << "?? Are you absolutely sure? (y/n) ";
                        else
                            cout << "\nHeavens, not " << c[c_id].getName() << "?? Are you absolutely sure? (y/n) ";
                        cin >> param;
                        params.push_back(param);
                        countParam(params);
                        trimParam(params, 5);
                    } while(params[4] != "y" && params[4] != "n");

                    if(params[4] == "y")
                    {
                        if(isPerson)
                            service.del(p[p_id]);
                        else
                            service.del(c[c_id]);
                        cout << "\nGood-bye, you poor soul." << endl;
                    }
                    else
                    {
                        cout << "\nNothing was deleted. Godspeed." << endl;
                    }
                }

            } while(!canDel);
        }
        else
        {
            cerr << "But I will not give up. Never.\n" << endl;
            cerr << "Perhaps if you would add '" << params[2] << "' do the database, it" << endl;
            cerr << "would be easier for me to find this person and delete." << endl;
        }
    }
    else if(params[1] == "list" || params[1] == "l")
    {
        if(isPerson)
        {
            service.list(p);
            listsize = p.size();
            show(p);
        }
        else
        {
            service.list(c);
            listsize = c.size();
            show(c);
        }

        do
        {
            trimParam(params, 2);
            cout << "Enter no. of the entry you want to delete (confirmation later required): ";
            cin >> param;
            params.push_back(param);
            countParam(params);
            trimParam(params, 3);

            isValidInput(params[2], listsize + 1, canDel);
            p_id = atoi(params[2].c_str())-1;
        } while(!canDel);

        if(canDel)
        {
            if(isPerson)
            {
                show(p[p_id]);
                cout << "\nWe're talking " << p[p_id].getFName() << " here. Is this correct? (y/n) ";
            }
            else
            {
                show(c[p_id]);
                cout << "\nWe're talking " << c[p_id].getName() << " here. Is this correct? (y/n) ";
            }

            cin >> param;
            params.push_back(param);
            countParam(params);
            trimParam(params, 4);

            while(params[3] != "y" && params[3] != "n")
            {
                trimParam(params, 3);
                cout << "\nAnswer the question please: (y/n) ";
                cin >> param;
                params.push_back(param);
                countParam(params);
                trimParam(params, 4);
            }

            if(params[3] == "y" || params[3] == "Y")
            {
                if(isPerson)
                    service.del(p[p_id]);
                else
                    service.del(c[p_id]);

                cout << "\nWow, that was weird. 'Tis over with." << endl;
            }
            else
            {
                cout << "\nThank heavens, you've seen the light!" << endl;
            }
        }
    }

    // Ef vitlaust var skrifað inn fyrir 'p' eða 'c'
    else
    {
        cerr << "\nWhat a curious choice, young apprentice. I believe I do not know this parameter." << endl;
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
        cout << "Type 'c' for a listing of Computers or" << endl;
        cout << "'p' for a listing of Programmers: ";
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
        service.list(p);
        show(p);
    }
    else if(params[0] == "c")
    {
        service.list(c);
        show(c);
    }
    else if(params[0] == "r")
    {
        rel();
    }

    // Error handling með smá attitude
    else
    {
        cerr << "The function 'list' does not use these funny parameters of yours." << endl;
    }

    if(params.size() > 1)
    {
        cerr << "Perhaps try to tone down your use of parameters a little bit." << endl;
    }

}

// Implement relations function
void ConsoleUI::rel()
{
    marriage m;
    vector<string> params = countParam();
    string param;

    PersonContainer p;
    CompContainer c;

    bool search_successful = false, isOK;

    int listsize =0, p_id, c_id;

    cout << "\nSearch for an entry to show relations." << endl;
    while(params.size() == 0 || (params[0] != "p" && params[0] != "c"))
    {
       // Taka inn parameterinn
       params.clear();
       cout << "Type 'c' to search from the Computers database " << endl;
       cout << "or 'p' to search from the Programmers database: ";
       cin >> param;
       params.push_back(param);
       trimParam(params, 1);
       vector<string> del = countParam();
    }

    if(params[0] == "p")
        m.isPerson = true;
    else
        m.isPerson = false;

    cout << m.isPerson << endl;
    cout << "Enter search string: ";
    cin.ignore(1000, '\n');
    getline(cin, param);
    params.push_back(param);

    cout << "\nYour search string is: \'" << params[1] << "\'";

    if(m.isPerson)
    {
        service.search(params[1], p, search_successful);
        listsize = p.size();
    }
    else
    {
        service.search(params[1], c, search_successful);
        listsize = c.size();
    }

    if(listsize == 1)
    {
        if(m.isPerson)
        {
            m.ID = p[0].getID();
            show(p);
        }
        else
        {
            m.ID = c[0].getID();
            show(c);
        }

        do
        {
            trimParam(params, 2);
            cout << "See relations for this entry? (y/n) ";
            cin >> param;
            params.push_back(param);
            countParam(params);
            trimParam(params, 3);

            if(params[2] == "y")
            {
                service.get_rel(m);
                for(unsigned int i = 0; i < m.relations.size(); i++)
                    cout << m.relations[i] << endl;
                //show(m);
            }
            else if(params[2] == "n" || params[2] == "N")
            {
                search_successful = true;
                cout << "\nPlease try again then. You can do it!" << endl;
            }
        } while(params[2] != "y" && params[2] != "n");
    }
    if(listsize > 1)
    {
        if(m.isPerson)
            show(p);
        else
            show(c);

        do
        {
            // Fa inn numerið a personu til að skoða
            trimParam(params, 2);
            cout << "Type the no. of the entry: ";
            cin >> param;
            params.push_back(param);
            countParam(params);
            trimParam(params, 3);

            isValidInput(params[2], listsize + 1, isOK);

            if(isOK)
            {
                if(m.isPerson)
                    m.ID = p[atoi(params[2].c_str()) - 1].getID();
                else
                    m.ID = c[atoi(params[2].c_str()) - 1].getID();
                service.get_rel(m);
                for(unsigned int i = 0; i < m.relations.size(); i++)
                    cout << m.relations[i] << endl;
                // show(m);
            }
        }while(!isOK && params[2] != "q");
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
                        cerr << "The sort function only has 2 parameters.";
                }
                else
                {
                    cerr << "\'" << params[1] << "\' is not a known parameter for the sort function";

                    if(params.size() > 2 && params[1] != "d")
                        cerr << " and only has 2 parameters";

                    cerr << "." << endl;
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
                    cerr << "\'" << nextparams[0] << "\' is not a paralegal." << endl;
                    cerr << "...uhm sorry. I meant legal parameter." << endl;
                }
            }
        }
    }

    // Sortum listann á þann hátt sem userinn bað um
    if(canSort)
    {
        PersonContainer sorted = service.sort_list(sort_after, desc);
        show(sorted);
    }
    else
    {
        cerr << "\nThe option does not exist. Give it another shot.\n" << endl;
    }
}

//Implement find function
void ConsoleUI::find()
{
    bool exists = false;
    bool done = false;
    string search, param;
    bool isPerson = true;

    // Öllu sem kom á eftir 'find' safnað saman í params vektorinn
    vector<string> params = countParam();

    while(params.size() == 0 || (params[0] != "p" && params[0] != "c"))
    {
        // Taka inn parameterinn
        cout << "Type 'c' to search the Computers database " << endl;
        cout << "or 'p' to search the Programmers database: ";
        cin >> param;

        if(params.size() == 0)
            params.push_back(param);
        else
            params[0] = str2lower(param);
    }

    if(params[0] == "p")
        isPerson = true;
    else if(params[0] == "c")
        isPerson = false;

    // Tékkað hvort einhverjir parametrar voru
    // Í þessu tilfelli eru parametrarnir strengur og því öllu sem
    // á eftir 'find' kom safnað saman í strenginn 'search'
    if(params.size() > 1 && (params[0] == "p" || params[0] == "c"))
        {
            done = true;

            for(unsigned int i = 1; i < params.size(); i++)
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
    PersonContainer p_found, p_temp;
    CompContainer c_found, c_temp;

    if(isPerson)
        p_found = service.find_p(search, p_temp, exists);
    else
        c_found = service.find_p(search, c_temp, exists);

    if(exists == false)
    {
        cerr << "\nSearch did not give any results." << endl;
    }
    else
    {
        cout << "\nI admire your search skills." << endl;

        if(isPerson)
        {
            cout << "\'" << search << "\' was found in " << p_found.size() << " entries:" << endl;
            show(p_found);
        }
        else
        {
            cout << "\'" << search << "\' was found in " << c_found.size() << " entries:" << endl;
            show(c_found);
        }
    }
}

// Fall sem prentar út lista eftir vektor sem er gefinn með mörgum persónum í
void ConsoleUI::show(const PersonContainer& listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "\nNo one in database!" << endl;
    }
    else
    {

        cout << "\n+-----------------------------------------------------------------------+" << endl;
        cout << setw(3) << "No."
             << setw(37) << "Name"
             << setw(18) << "Nationality"
             << setw(5) << "Born"
             << setw(5) << "Dead"
             << setw(5) << "Sex"
             << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << setw(3) << i+1;
            cout << listed[i];
        }
        cout << "+-----------------------------------END---------------------------------+\n" << endl;
     }
}

void ConsoleUI::show(const CompContainer& listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "\nNo one in database!" << endl;
    }
    else
    {

        cout << "\n+------------------------------------------------------+" << endl;
        cout << setw(3) << "No."
             << setw(27) << "Name"
             << setw(15) << "Type"
             << setw(5) << "Year"
             << setw(6) << "Built"
             << endl;
        cout << "+------------------------------------------------------+" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << setw(3) << i+1;
            cout << listed[i];
        }
        cout << "+----------------------------END-----------------------+\n" << endl;
     }
}

// Fall sem prentar út einstakling
void ConsoleUI::show(const Person& listed)
{
    cout << "\n+-----------------------------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << setw(37) << "Name"
         << setw(18) << "Nationality"
         << setw(5) << "Born"
         << setw(5) << "Dead"
         << setw(5) << "Sex"
         << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << listed;
    cout << "+-----------------------------------END---------------------------------+\n" << endl;
}

void ConsoleUI::show(const Computer& listed)
{
    cout << "\n+------------------------------------------------------+" << endl;
    cout << setw(3) << "No."
         << setw(27) << "Name"
         << setw(15) << "Type"
         << setw(5) << "Year"
         << setw(6) << "Built"
         << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << listed;
    cout << "+----------------------------END-----------------------+\n" << endl;
}

void ConsoleUI::show(const bool& isPerson, const int& ID, const vector<int>& relations)
{
    if(isPerson)
    {

    }
}

// isValidInput athugar hvort id sé leyfilegt (innan marka), isOK verður þá true
// og tekur strenginn inp og kastar yfir í int og skilar því.
int ConsoleUI::isValidInput(const string& inp, const int& lessThan, bool& isOK)
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
void ConsoleUI::printComms()
{
    cout << "\n[add] [del] [list] [find] [sort] [quit]" << endl;
}

// Fall til að taka inn parametra og skila þeim í vektor af strengjum
vector<string> ConsoleUI::countParam()
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
            p.push_back(str2lower(param));
        }
    }
    else
    {
        cin.putback(nextin);
    }

    return p;
}

void ConsoleUI::countParam(vector<string>& result)
{
    vector<string> params = countParam();

    for(unsigned int i = 0; i < params.size(); i++)
        result.push_back(params[i]);
}

void ConsoleUI::trimParam(vector<string>& result, const int& keep)
{
    result.erase(result.begin() + keep, result.begin() + result.size());
}
