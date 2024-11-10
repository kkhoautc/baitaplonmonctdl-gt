#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
    public:
    TrieNode* children[26]; 
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    bool hasChildren() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                return true; 
            }
        }
        return false; 
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    void insertNum(const string& phoneNumber) {
        TrieNode* current = root;
        for (char c : phoneNumber) {
            int index = c - '0'; 
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

	//tien to
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
    int checkPrefixExists(const string& word) {
    	int check=1;
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index]==nullptr) {
            	check=0;
                break;
            }
            current = current->children[index];
        }
        if(check==1&&!current->hasChildren()){  //check xem co trung khong
        	check=0;
		}
        return check;
    }
    //ham tim sdt nay co phai la tien to cua cac so con lai khong
    bool isPrefixOfAll(const string& prefix, int totalNumbers) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - '0';
            if (node->children[index] == nullptr) {
                return false; 
            }
            node = node->children[index];
        }
        int count = countAllNumbers(node);
        return (count == totalNumbers); 
    }
    //tinh sdt nay la tien to cua bao nhieu sdt khac
    int countAllNumbers(TrieNode* node) {
    	int count;
    	if(node->isEndOfWord){
    		count=1;
		}
		else count=0;
        for (int i = 0; i < 10; ++i) {
            if (node->children[i] != nullptr) {
                count += countAllNumbers(node->children[i]);
            }
        }
        return count;
    }
    //ham check xem co so nao la tien to cac so cin lai khong
    //
    void findPrefixOfAll(const vector<string>& phoneNumbers) {
    	int check=1;
    	int n = phoneNumbers.size();
    	for (const string& number : phoneNumbers) {
        	if (isPrefixOfAll(number, n)) {
            	cout << "Co !!! . Ket qua: \n" << number << endl;
            	check=0;
				break;
				
        	}
    	}
    	if(check){
    		cout << "KHONG CO!!!\n";
		}
   
	}

	//ham tu dong hoan thanh tu
	//tim kiem prefix va tra ve node
	TrieNode* searchPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }
    // ham kiem cac ki tu va ghep vao tu
    void collectWords(TrieNode* node, string prefix, vector<string>& results) {
        if (node->isEndOfWord) {
            results.push_back(prefix);
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                char nextChar = 'a' + i;
                collectWords(node->children[i], prefix + nextChar, results);
            }
        }
    }
    // tim kiem cac tu tra ve vector string ketqua
    vector<string> autocomplete(const string& prefix) {
        vector<string> results;
        TrieNode* node = searchPrefix(prefix);
        if (node != nullptr) {
            collectWords(node, prefix, results);
        }
        return results;
    }
};
	
int main() {
    Trie trie;
    vector<string> words;
    int choice;
    do{	
    	cout << "\n---MENU---"; 
		cout << "1.Them n xau" <<endl;
		cout << "2.Them n so dien thoai" <<endl;
		cout << "3.Co ton tai xau nao la tien to cua xau nao khong?" <<endl;
		cout << "4.Co so nao la tien to cua cac so con lai khong?" <<endl;
		cout << "5.Tu dong hoan thanh tu"<<endl;
		cout << "0.Thoat"<<endl;
	    cout << "Lua chon cua ban: ";
	    cin >> choice;
	            
	
    	switch(choice){
    		case 1: {
    			cout << "Nhap so luong xau muon them: ";
	    		int n;
	    		cin >> n;
	    		for (int i = 0; i < n; i++) {
	        		string x;
	        		cin >> x;
	        		words.push_back(x);
	        		trie.insert(x);
	    		}
	    		
	    		break;
	    	}
    		case 2:{
	    		cout << "nhap so luong sdt can them: " << endl;
	    		int n;cin >> n;
	    		for (int i = 0; i < n; i++) {
	    			string x;
	    			cin >> x;
	        		words.push_back(x);
	        		trie.insertNum(x);
	    		}
	    		break;
	    	}
	    	case 3:{
	    		for (int i = 0; i < words.size(); i++) {
			        if (trie.checkPrefixExists(words[i])) {
			            cout << words[i] <<" la 1 tien to\n"; 
			        }
		    	}
		        break;
			}
		    case 4:{
				trie.findPrefixOfAll(words);
				
    			break;
    		}
	    	case 5:{
				string prefix;
			    cout << "Nhap tien to can goi y: ";
			    cin >> prefix;
			
			    vector<string> suggestions = trie.autocomplete(prefix);
			
			    cout << "cac goi y cho tien to la: \"" << prefix << "\":\n";
			    if (suggestions.empty()) {
			        cout << "Khong co goi y nao.\n";
			    } else {
			        for (const string& word : suggestions) {
			            cout << word << endl;
			        }
			    }
			    
				break;
			}	
			default:{
				cout << "Lua chon khong hop le.\n";
				break;
			}
		}
	}while(choice!=0);

}
