#include <iostream>
#include <string.h>
#include <time.h>
#include "CNode.h"
#include "CVirtualNode.h"
#include "CHashFun.h"
#include "CMD5HashFun.h"
#include "CConsHash.h"

using namespace std;

void getIP(char *IP)
{
    int a = 0, b = 0, c = 0, d = 0;
    a = rand() % 256;
    b = rand() % 256;
    c = rand() % 256;
    d = rand() % 256;
    char aa[4], bb[4], cc[4], dd[4];
	sprintf(aa, "%d", a);
	sprintf(bb, "%d", b);
	sprintf(cc, "%d", c);
	sprintf(dd, "%d", d);
    strcpy(IP, aa);
    strcat(IP, ".");
    strcat(IP, bb);
    strcat(IP, ".");
    strcat(IP, cc);
    strcat(IP, ".");
    strcat(IP, dd);
}

int main()
{   
    srand(time(NULL));
    freopen("out.txt", "r", stdin);
    CHashFun *func = new CMD5HashFun();
    CConsHash *conhash = new CConsHash(func);

	char pdata1[20] = {0};
	char pdata2[20] = {0};
	char pdata3[20] = {0};
	char pdata4[20] = {0};
	strcpy(pdata1, "10.3.0.201");
	strcpy(pdata2, "10.3.0.202");
	strcpy(pdata3, "10.3.0.203");
	strcpy(pdata4, "10.3.0.204");

    CNode *node1 = new CNode("machineA", 50, pdata1);
    CNode *node2 = new CNode("machineB", 80, pdata2);
    CNode *node3 = new CNode("machineC", 90, pdata3);
    CNode *node4 = new CNode("machineD", 100, pdata4);

    conhash->addNode(node1);
    conhash->addNode(node2);
    conhash->addNode(node3);
    conhash->addNode(node4);

    int ans1, ans2, ans3, ans4;
    ans1 = ans2 = ans3 = ans4 = 0;

    char object[100];
    CNode *node;
    //conhash->delNode(node2);

	cout << "total nodes:" << conhash->getVNode() << endl;

    for ( int i = 0; i < 1000000; i++ ) {
		getIP(object);
        cin >> object;
        node = conhash->lookupNode(object);
        if ( node != NULL ) {
            //cout << object << "---->\t" << node->getIden() << " \t " << (char *)node->getData() << endl;
            if ( strcmp(node->getIden(), "machineA" ) == 0 ) ans1++;
            if ( strcmp(node->getIden(), "machineB" ) == 0 ) ans2++;
            if ( strcmp(node->getIden(), "machineC" ) == 0 ) ans3++;
            if ( strcmp(node->getIden(), "machineD" ) == 0 ) ans4++;
        }
    }

    cout << "Total test cases : " << ans1 + ans2 + ans3 + ans4 << endl;
    cout << " map to machineA : " << ans1 << endl;
    cout << " map to machineB : " << ans2 << endl;
    cout << " map to machineC : " << ans3 << endl;
    cout << " map to machineD : " << ans4 << endl;

    fclose(stdin);

    return 0;
}
