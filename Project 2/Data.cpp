/* 
 * File:   Data.cpp
 * Author: Michael
 *
 * Created on June 2, 2014, 8:20 PM
 */

#include "Data.h"

using namespace std;

/**
 * Constructor
 * @param filename
 */
Data::Data( string file ){
    totalRecords = 0;
    fileName = file;   
}

/**
 * copy constructor
 * @param obj
 */
Data::Data( const Data &obj ){
    totalRecords = obj.totalRecords;
    fileName = obj.fileName;
    for( int i = 0; i < obj.employees.size(); i++ ){
        employees.push_back( obj.employees.at( i ) );
    }
    for( int i = 0; i < obj.interns.size(); i++ ){
        interns.push_back( obj.interns.at( i ) );
    }
    for( int i = 0; i < obj.volunteers.size(); i++ ){
        volunteers.push_back( obj.volunteers.at( i ) );
    }
}

void Data::operator = ( const Data &right ){
    totalRecords = right.totalRecords;
    fileName = right.fileName;
    for( int i = 0; i < right.employees.size(); i++ ){
        employees.push_back( right.employees.at( i ) );
    }
    for( int i = 0; i < right.interns.size(); i++ ){
        interns.push_back( right.interns.at( i ) );
    }
    for( int i = 0; i < right.volunteers.size(); i++ ){
        volunteers.push_back( right.volunteers.at( i ) );
    }
}

/**
 * push back to employee vector
 * @param e
 */
void Data::pushBackEmployee(Employee e ){
    employees.push_back( e );
}

/**
 * push back to intern vector
 * @param i
 */
void Data::pushBackIntern(Intern i ) {
    interns.push_back( i );
}

/**
 * push back to volunteer vector
 * @param v
 */
void Data::pushBackVolunteer(Volunteer v){
    volunteers.push_back( v );
}

/**
 * save all the date to default file
 */
void Data::save(){
    save( getFileName() );
}

/**
 * save all the data to custom file
 * @param fileName
 */
void Data::save( string fileName ) {
    fstream file;
    file.open( fileName.c_str(), ios::out );
    
    for( int i = 0; i < employees.size(); i++ ){
        file << employees.at( i ).toString() << '\n';
    }
    
    for( int i = 0; i < interns.size(); i++ ){
        file << interns.at( i ).toString() << '\n';
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        file << volunteers.at( i ).toString() << '\n';
    }
    
    file.close();
}

/**
 * load the data from the default save location
 */
void Data::load(){
    load( getFileName() );
}

/**
 * load the data from a custom save location
 * @param 
 */
void Data::load( string filename ){
    //clear the current data
    clear();
    
    fstream file;
    file.open( filename.c_str(), ios::in );
    //check bad file
    if ( file.fail() ){
        cout << "Could not open file\n";
        return;
    }
    //read the file
    string line;
    int objCount = 0;
    //get the object count
    getline(file, line);
    
    while (file) {
        // Display the last item read.
        objCount++;

        // Read the next item.
        getline( file, line );
    }
    //rewind the file
    file.clear();
    file.seekg( 0L, ios::beg );
    string type;
    vector<string> data[objCount];
    bool isReadingObj = false;
    int i = 0;
    
    //read the file the old school way cause it works for me and cause i didn't look up how to str split
    while( file >> line ){
        if( line == "emp" || line == "int" || line == "vol" ) { 
            //then this is the type of employee
            type = line;
            isReadingObj = true;
        }
        else if( line == "~" ) {
            isReadingObj = false;
            i++; // inc obj
        }
        
        if( isReadingObj ){
            data[i].push_back( line );
        }
    }
    file.close();
    int id = 0;
    for( i = 0; i < objCount; i++ ){

        if( data[i].at( 0 ) == "emp" ) {
            id = atoi( data[i].at( 1 ).c_str() ); // c-string to int
            Employee emp( id );
            emp.setFname( data[i].at( 2 ) );
            emp.setLname( data[i].at( 3 ) );
            emp.setAge( atoi( data[i].at( 4 ).c_str() ) );
            emp.setSex( atoi( data[i].at( 5 ).c_str() ) );
            emp.setPayrate( atof( data[i].at( 6 ).c_str() ) );
            emp.setHours( atof( data[i].at( 7 ).c_str() ) );
            pushBackEmployee( emp );
        }
        else if( data[i].at( 0 ) == "int" ){
            id = atoi( data[i].at( 1 ).c_str() ); // c-string to int
            Intern in( id );
            in.setFname( data[i].at( 2 ) );
            in.setLname( data[i].at( 3 ) );
            in.setAge( atoi( data[i].at( 4 ).c_str() ) );
            in.setSex( atoi( data[i].at( 5 ).c_str() ) );
            bool isPaid = ( atoi( data[i].at( 6 ).c_str() ) == 0 ? false : true );
            in.setIsPaid( isPaid );
            in.setPayrate( atof( data[i].at( 7 ).c_str() ) );
            in.setHours( atof( data[i].at( 8 ).c_str() ) );
            pushBackIntern( in );
        }
        else if( data[i].at( 0 ) == "vol" ){
            id = atoi( data[i].at( 1 ).c_str() ); // c-string to int
            Volunteer vol( id );
            vol.setFname( data[i].at( 2 ) );
            vol.setLname( data[i].at( 3 ) );
            vol.setAge( atoi( data[i].at( 4 ).c_str() ) );
            vol.setSex( atoi( data[i].at( 5 ).c_str() ) );
            vol.setHours( atof( data[i].at( 6 ).c_str() ) );
            pushBackVolunteer( vol );
        }
    }
    save();
}

/**
 * clears the stored data so it can load new data from file
 */
void Data::clear(){
    totalRecords = 0;
    employees.clear();
    interns.clear();
    volunteers.clear();
}

/**
 * print out all employees
 * @param type
 */
void Data::printFormatedPerson( int type ){
    if( type == 0 ){
        for( int i = 0; i < employees.size(); i++ ){
            printEmployee( i );
        }
    }
    else if( type == 1 ){
        for( int j = 0; j < interns.size(); j++ ){
            printIntern( j );
        }
    }
    else if( type == 2 ){
        for( int k = 0; k < volunteers.size(); k++ ){
            printVolunteer( k );
        }
    }   
    else {
        return;
    }
}

/**
 * print out a single employee
 * @param index
 * @param isPay
 */
void Data::printEmployee( int index, bool isPay ){
    cout << '|'<< setw( 6 ) << employees.at( index ).getId() << " |" <<
        setw( 18 ) << employees.at( index ).getFname() << " |" << 
        setw( 18 ) << employees.at( index ).getLname() << " |"; 
    if ( !isPay ) {
        cout << setw( 4 ) << employees.at( index ).getAge() << " |" << 
        setw( 4 ) << employees.at( index ).getSexLetter() << " |" << 
        setw( 9 ) << employees.at( index ).getPayrate() << " |" <<
        setw( 6 ) << employees.at( index ).getHours() << " |"; 
    }
    else{
        cout << setw( 9 ) << employees.at( index ).getPay() << " |";
    }     
    cout << " empl |";
    cout << endl;
}

/**
 * print out a single employee
 * @param index
 * @param isPay
 */
void Data::printIntern( int index, bool isPay ){
    Intern intern = interns.at( index );
    cout << '|'<< setw( 6 ) << interns.at( index ).getId() << " |" <<
        setw( 18 ) << interns.at( index ).getFname() << " |" << 
        setw( 18 ) << interns.at( index ).getLname() << " |";
    if( !isPay ){
        cout << setw( 4 ) << interns.at( index ).getAge() << " |" << 
        setw( 4 ) << interns.at( index ).getSexLetter() << " |" << 
        setw( 9 ) << interns.at( index ).getPayrate() << " |" <<
        setw( 6 ) << interns.at( index ).getHours() << " |";
    }
    else{
        cout << setw( 9 ) << interns.at( index ).getPay() << " |";
    }
    cout << " inte |";
    cout << endl;
}

/**
 * print out a single employee
 * @param index
 * @param isPay
 */
void Data::printVolunteer( int index, bool isPay ){
    cout << '|'<< setw( 6 ) << volunteers.at( index ).getId() << " |" <<
        setw( 18 ) << volunteers.at( index ).getFname() << " |" << 
        setw( 18 ) << volunteers.at( index ).getLname() << " |";
    if ( !isPay ){
        cout << setw( 4 ) << volunteers.at( index ).getAge() << " |" << 
        setw( 4 ) << volunteers.at( index ).getSexLetter() << " |" << 
        setw( 9 ) << 0 << " |" <<
        setw( 6 ) << volunteers.at( index ).getHours() << " |";
    }
    else{
        cout << setw( 9 ) << volunteers.at( index ).getPay() << " |";
    }
    cout << " volu |";
    cout << endl;
}

/**
 * @deprecated
 * search for a id of an employee
 * @param id
 */
void Data::searchId( int id ){
    int found = 0;
    for( int i = 0; i < employees.size(); i++ ){
        if ( id == employees.at( i ).getId() ){
            printEmployee( i );
            found++;
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if ( id == interns.at( i ).getId() ){
            printIntern( i );
            found++;
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if ( id == volunteers.at( i ).getId() ){
            printVolunteer( i );
            found++;
        }
    }
    
    if( found == 0){
        cout << "No Results\n";
    }
}

/**
 * search by name
 * @param name
 * @param isFirst
 */
void Data::searchName(string name, bool isFirst ){
    int count = 0;
    size_t found;
    for( int i = 0; i < employees.size(); i++ ){
        if( isFirst ){
            found = employees.at( i ).getFname().find( name );
        }
        else{
            found = employees.at( i ).getLname().find( name );
        }
        
        if( found != string::npos ){
            count++;
            printEmployee( i );
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if( isFirst ){
            found = interns.at( i ).getFname().find( name );
        }
        else{
            found = interns.at( i ).getLname().find( name );
        }
        
        if( found != string::npos ){
            count++;
            printIntern( i );
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if( isFirst ){
            found = volunteers.at( i ).getFname().find( name );
        }
        else{
            found = volunteers.at( i ).getLname().find( name );
        }
        
        if( found != string::npos ){
            count++;
            printVolunteer( i );
        }
    }
    
    if( count == 0 ){
        cout << "No Results Found\n";
    }
}

/**
 * got tired of copying and pasting new search
 * @param type 0 id, 1 age, 2 sex, 3 pay
 * @param num
 * @param fnum
 */
void Data::search( int type, int num, float fnum ){
    // 0 id, 1 age, 2 sex, 3 pay
    int found = 0;
    for( int i = 0; i < employees.size(); i++ ){
        switch( type ){
            case 0:
                if ( num == employees.at( i ).getId() ){
                    printEmployee( i );
                    found++;
                }
                break;
            case 1:
                if ( num == employees.at( i ).getAge() ){
                    printEmployee( i );
                    found++;
                }
                break;
            case 2:
                if ( num == employees.at( i ).getSex() ){
                    printEmployee( i );
                    found++;
                }
                break;
            case 3:
                if ( fnum == employees.at( i ).getPayrate() ){
                    printEmployee( i );
                    found++;
                }
                break;  
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        switch( type ){
            case 0:
                if ( num == interns.at( i ).getId() ){
                    printIntern( i );
                    found++;
                }
                break;
            case 1:
                if ( num == interns.at( i ).getAge() ){
                    printIntern( i );
                    found++;
                }
                break;
            case 2:
                if ( num == interns.at( i ).getSex() ){
                    printIntern( i );
                    found++;
                }
                break;
            case 3:
                if ( fnum == interns.at( i ).getPayrate() ){
                    printIntern( i );
                    found++;
                }
                break;  
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        switch( type ){
            case 0:
                if ( num == volunteers.at( i ).getId() ){
                    printVolunteer( i );
                    found++;
                }
                break;
            case 1:
                if ( num == volunteers.at( i ).getAge() ){
                    printVolunteer( i );
                    found++;
                }
                break;
            case 2:
                if ( num == volunteers.at( i ).getSex() ){
                    printVolunteer( i );
                    found++;
                }
                break;
            case 3:
                if ( fnum == 0 ){
                    printVolunteer( i );
                    found++;
                }
                break;  
        }
    }
    
    if( found == 0){
        cout << "No Results\n";
    }
}

/**
 * set the hours worked for an employee
 * @param id
 * @param hours
 */
void Data::setHours( int id, float hours ){
    for( int i = 0; i < employees.size(); i++ ){
        if ( id == employees.at( i ).getId() ){
            employees.at( i ).setHours( hours );
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if ( id == interns.at( i ).getId() ){
            interns.at( i ).setHours( hours );
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if ( id == volunteers.at( i ).getId() ){
            volunteers.at( i ).setHours( hours );
        }
    }
}

/**
 * get pay for one employee or all of them
 * @param id
 */
void Data::getPay( int id ) {
    for( int i = 0; i < employees.size(); i++ ){
        if ( id != -1 && id == employees.at( i ).getId() ){
            printEmployee( i, true );
        }
        else if( id == -1) {
            printEmployee( i, true );
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if ( id != -1 && id == interns.at( i ).getId() ){
            printIntern( i, true );
        }
        else if( id == -1) {
            printIntern( i, true );
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if ( id != -1 && id == volunteers.at( i ).getId() ){
            printVolunteer( i, true );
        }
        else if( id == -1) {
            printVolunteer( i, true );
        }
    }
}

/**
 * Edit the employee
 * @param id
 */
void Data::edit( int id ){
    if ( isUnqiueId( id ) ){
        cout << "No Employee with That Id\n";
        return;
    }
    
    char option;
    do{
        cout << "Edit menu\n";
        cout << "Press f ----> Edit First Name\n";
        cout << "Press l ----> Edit Last Name\n";
        cout << "Press a ----> Edit Age\n";
        cout << "Press s ----> Edit Sex\n";
        cout << "Press p ----> Edit Pay Rate\n";
        cout << "Press h ----> Edit Hours\n";
        cout << "Press q ----> Stop Editing\n";
        cin >> option;
        
        string str;
        int num;
        float fnum;
        switch( option ){
            case 'f':
                cout << "Enter new first name\n";
                cin.ignore();
                getline( cin, str );
                for( int i = 0; i < employees.size(); i++ ){
                    if ( id == employees.at( i ).getId() ){
                        employees.at( i ).setFname( str );
                    }
                }
                for( int i = 0; i < interns.size(); i++ ){
                    if ( id == interns.at( i ).getId() ){
                        interns.at( i ).setFname( str );
                    }
                }
                for( int i = 0; i < volunteers.size(); i++ ){
                    if ( id == volunteers.at( i ).getId() ){
                        volunteers.at( i ).setFname( str );
                    }
                }
                break;
            case 'l':
                cout << "Enter new last name\n";
                cin.ignore();
                getline( cin, str );
                for( int i = 0; i < employees.size(); i++ ){
                    if ( id == employees.at( i ).getId() ){
                        employees.at( i ).setLname( str );
                    }
                }
                for( int i = 0; i < interns.size(); i++ ){
                    if ( id == interns.at( i ).getId() ){
                        interns.at( i ).setLname( str );
                    }
                }
                for( int i = 0; i < volunteers.size(); i++ ){
                    if ( id == volunteers.at( i ).getId() ){
                        volunteers.at( i ).setLname( str );
                    }
                }
                break;
            case 'a':
                cout << "Enter new age\n";
                cin >> num;
                for( int i = 0; i < employees.size(); i++ ){
                    if ( id == employees.at( i ).getId() ){
                        employees.at( i ).setAge( num );
                    }
                }
                for( int i = 0; i < interns.size(); i++ ){
                    if ( id == interns.at( i ).getId() ){
                        interns.at( i ).setAge( num );
                    }
                }
                for( int i = 0; i < volunteers.size(); i++ ){
                    if ( id == volunteers.at( i ).getId() ){
                        volunteers.at( i ).setAge( num );
                    }
                }
                break;
            case 's':
                do{
                    cout << "Enter new sex\n";
                    cin >> option;
                }
                while( option != 'f' && option != 'm' );
                for( int i = 0; i < employees.size(); i++ ){
                    if ( id == employees.at( i ).getId() ){
                        employees.at( i ).setSex( ( option == 'f' ? 0 : 1 ) );
                    }
                }
                for( int i = 0; i < interns.size(); i++ ){
                    if ( id == interns.at( i ).getId() ){
                        interns.at( i ).setSex( ( option == 'f' ? 0 : 1 ) );
                    }
                }
                for( int i = 0; i < volunteers.size(); i++ ){
                    if ( id == volunteers.at( i ).getId() ){
                        volunteers.at( i ).setSex( ( option == 'f' ? 0 : 1 ) );
                    }
                }
                break;
            case 'p':
                cout << "Enter new pay rate\n";
                cin >> fnum;
                for( int i = 0; i < employees.size(); i++ ){
                    if ( id == employees.at( i ).getId() ){
                        employees.at( i ).setPayrate( fnum );
                    }
                }
                for( int i = 0; i < interns.size(); i++ ){
                    if ( id == interns.at( i ).getId() ){
                        interns.at( i ).setPayrate( fnum );
                    }
                }
                break;
            case 'h':
                cout << "Enter hours\n";
                cin >> fnum;
                setHours( id, fnum );
                break;
        }
    }
    while( option != 'q' );
    
    save();       
}

void Data::setFileName(string s ) {
    fileName = s;
}

/**
 * delete a employee by id
 * @param id
 * @return 
 */
bool Data::deleteById( int id ) {
    for( int i = 0; i < employees.size(); i++ ){
        if ( id == employees.at( i ).getId() ){
            employees.erase( employees.begin() + i );
            save();
            return true;
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if ( id == interns.at( i ).getId() ){
            interns.erase( interns.begin() + i );
            save();
            return true;
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if ( id == volunteers.at( i ).getId() ){
            volunteers.erase( volunteers.begin() + i );
            save();
            return true;
        }
    }
    
    //failed to delete by this point
    return false;
}

/**
 * checks if the id is use or not
 * @param id
 * @return 
 */
bool Data::isUnqiueId( int id ){
    for( int i = 0; i < employees.size(); i++ ){
        if ( id == employees.at( i ).getId() ){
            return false;
        }
    }
    for( int i = 0; i < interns.size(); i++ ){
        if ( id == interns.at( i ).getId() ){
            return false;
        }
    }
    
    for( int i = 0; i < volunteers.size(); i++ ){
        if ( id == volunteers.at( i ).getId() ){
            return false;
        }
    }
    return true;
}

int Data::getTotalRecords(){
    totalRecords = employees.size() + interns.size() + volunteers.size();
    return totalRecords;
}

string Data::getFileName(){
    return fileName;
}

vector<Employee> Data::getEmployees(){
    return employees;
}

vector<Intern> Data::getInterns(){
    return interns;
}

vector<Volunteer> Data::getVolunteers(){
    return volunteers;
}
