#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <fstream>

using namespace std;

struct matrixElement
{
    int value;
    string direction;
    int i;
    int j;
};

struct returnFuction{
    vector < vector <matrixElement>> matrix;
    matrixElement maxGlobal;
};

struct finalAnswer{
    string dnaA;
    string dnaB;
    int score;
};

int score(char a, char b)
{
    if (a == b)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

//Nao sei como dizer que a funcao vai retornar uma matrix de struct e um struct talvez criar uma struct que tem:
// Matrix de matrixElement  e um matrixElement
//retorna uma matrix do struct e um elemento isolado da matrix

returnFuction calculateMatrix(int n,int m, string dna1, string dna2)
{

    //cria a matrix nao sei se eh assim!!!
    // matrixElement H[n + 1][m + 1];

    vector < vector <matrixElement>> H;
    H.resize(n+1);

    for(int linha = 0; linha < n+1; linha++){
        H[linha].resize(m+1);
    }

    int diagonal, delecao, insercao;
    matrixElement globalMax;
    globalMax.value = 0;



    // calcula a matrix
    //linha = i; coluna = j
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            matrixElement currentElement;
            currentElement.i = i;
            currentElement.j = j;

            int w = score(dna1[i - 1], dna2[j - 1]);

            diagonal = H[i - 1][j - 1].value + w;
            delecao = H[i - 1][j].value - 1;
            insercao = H[i][j - 1].value - 1;

            // calcula maximo entre os tres
            int max = std::max({0, diagonal, delecao, insercao});
            currentElement.value = max;

            
            
            // verifica de que direcao o maximo veio
            if (max == diagonal || max == 0)
            {
                currentElement.direction = "diagonal";
            }
            else if (max == delecao)
            {
                currentElement.direction = "delecao";
            }
            else
            {
                currentElement.direction = "insercao";
            }

            // adiciona o elemento na matrix
            H[i][j] = currentElement;

            if (currentElement.value >= globalMax.value){

                //nao sei se posso fazer isso, talvez, tenha que fazer separado
                globalMax = currentElement;
            }


        }
    }

    returnFuction resp;

    resp.matrix = H;
    resp.maxGlobal = globalMax;

    return resp;
}


finalAnswer get_path(returnFuction resp, string dnaA, string dnaB){
    string dnaAMatch;
    string dnaBMatch;
    vector <matrixElement> path;
    matrixElement currentElement;
    currentElement = resp.maxGlobal;
    matrixElement nextElement;
    // path.push_back(currentElement);
    //meio confuso sepa ta errado!


    while(currentElement.value != 0){

        int i = currentElement.i;
        int j = currentElement.j;
        if (currentElement.direction == "diagonal"){
        
            nextElement = resp.matrix[i - 1][j - 1];
            
            dnaAMatch += dnaA[i-1];
            dnaBMatch += dnaB[j-1];


        }else if (currentElement.direction == "delecao"){
            
            nextElement = resp.matrix[i-1][j];

            dnaAMatch += dnaA[i-1];
            dnaBMatch += "_";
        
        }else{
            
            nextElement = resp.matrix[i][j-1];;
            dnaAMatch += "_";
            dnaBMatch += dnaB[j-1];
        }

        currentElement = nextElement;
        // path.push_back(currentElement);
    }

    string dnaAreverso (dnaAMatch.rbegin(), dnaAMatch.rend());
    string dnaBreverso (dnaBMatch.rbegin(), dnaBMatch.rend());

    finalAnswer resposta;
    resposta.dnaA = dnaAreverso;
    resposta.dnaB = dnaBreverso;
    resposta.score = resp.maxGlobal.value;

    return resposta;
}

int main(){
    // ifstream myfile;
    // myfile.open ("dna.seq");

    string dnaA,dnaB;
    int n,m;

    cin >> n;
    cin >> m;
    cin >> dnaA;
    cin >> dnaB;
    returnFuction resp = calculateMatrix(n,m,dnaA,dnaB);


    // IMPRIMI A MATRIZ COMPLETA
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << resp.matrix[i][j].value << " ";
    //     }
            
    //     // Newline for new row
    //     cout << endl;
    // }



    finalAnswer final = get_path(resp,dnaA,dnaB);
    cout<< final.dnaA << endl;
    cout<< final.dnaB << endl;
    cout << final.score << endl;

}