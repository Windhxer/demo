#include <iostream>
#include <cstring>
#include <iomanip>//to make sure the accuracy

using namespace std;

using namespace std;

class Node
{
public:
    int num;
    string name;  // 该节点所保存的数据量
    int score[3];  // 子节点数
    Node ()
    {}
    
    void print ()
    {
        cout << num << "\t" << name << "\t";
        for(int i=0;i<=2;i++){
            cout << score[i] << "\t";
        }
        cout << (score[0] + score[1] + score[2])/3 << endl;
    }
    
    void scan(int i){
        num = i;
        cin >> name;cin >> score[0];cin >> score[1];cin >> score[2];
    }
};


int main(){
    Node student[10];
    int sumScore[3], maxScore[3], minScore[3];//to store the related score
    memset(sumScore, 0, 3 * sizeof(sumScore[0]));//initialize
    memset(maxScore, 0, 3 * sizeof(maxScore[0]));
    memset(minScore, 0xE, 3 * sizeof(minScore[0]));
    for(int i=0;i<=9;i++){
        student[i].scan(i+1);
    }
    cout << student[1].name << endl;
    cout << "no\t" << "name\t" << "score1\t" << "score2\t" << "score3\t" << "average\t" << endl;//print the text
    for(int i=0; i<10; i++) {
        student[i].print();
        for(int j=0;j<=2;i++){
            maxScore[j] = max(student[i].score[i],maxScore[j]);
            minScore[j] = min(student[i].score[i],maxScore[j]);
            sumScore[j] += student[i].score[j];
        }
    }
    
    cout << "\t" << "average\t";
    for(int i=0; i<3; i++){
        //printf("%.1f\t", (double)sumScore[i]/10);	//can't make sure how to use cout
        cout << fixed << setprecision(1) << (double)sumScore[i]/10 << "\t"; 
    }//to make sure the accuracy
    cout << endl; 
    
    cout << "\t" << "min\t";
    for(int i=0; i<3; i++)
        cout << minScore[i] << "\t";
    cout << endl;
    
    cout << "\t" << "max\t";
    for(int i=0; i<3; i++)
        cout << maxScore[i] << "\t";
    cout << endl;//print the related 'min,max,average'
    
    return 0;
}
