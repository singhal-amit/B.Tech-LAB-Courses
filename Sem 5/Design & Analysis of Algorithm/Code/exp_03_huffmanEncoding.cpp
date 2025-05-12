#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

// Node of Huffman Tree
struct Node
{
  char ch;
  int freq;
  Node *left, *right;

  Node(char ch, int freq, Node *left = nullptr, Node *right = nullptr)
  {
    this->ch = ch;
    this->freq = freq;
    this->left = left;
    this->right = right;
  }
};

// Comparison function for priority queue
struct compare
{
  bool operator()(Node *left, Node *right)
  {
    return left->freq > right->freq;
  }
};

// Function to build the Huffman Tree
Node *buildHuffmanTree(const unordered_map<char, int> &freq)
{
  priority_queue<Node *, vector<Node *>, compare> pq;

  for (auto pair : freq)
  {
    pq.push(new Node(pair.first, pair.second));
  }

  while (pq.size() != 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    int sum = left->freq + right->freq;
    pq.push(new Node('\0', sum, left, right));
  }

  return pq.top();
}

// Function to encode the input string
void encode(Node *root, const string &str, unordered_map<char, string> &huffmanCode)
{
  if (root == nullptr)
    return;

  if (!root->left && !root->right)
  {
    huffmanCode[root->ch] = str;
  }

  encode(root->left, str + "0", huffmanCode);
  encode(root->right, str + "1", huffmanCode);
}

// Function to decode the encoded string
string decode(Node *root, const string &str)
{
  string result = "";
  Node *curr = root;
  for (char bit : str)
  {
    if (bit == '0')
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }

    if (!curr->left && !curr->right)
    {
      result += curr->ch;
      curr = root;
    }
  }
  return result;
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)" << endl;

  string text;
  cout << "\nEnter the text to encode: ";
  getline(cin, text);

  unordered_map<char, int> freq;
  for (char ch : text)
  {
    freq[ch]++;
  }

  clock_t start = clock();
  Node *root = buildHuffmanTree(freq);
  clock_t end = clock();
  double time_taken_build_tree = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

  unordered_map<char, string> huffmanCode;
  start = clock();
  encode(root, "", huffmanCode);
  end = clock();
  double time_taken_encoding = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

  cout << "\nCharacter Encoding Table:" << endl;
  cout << "------------------------------" << endl;
  cout << setw(10) << "Character" << setw(20) << "Huffman Code" << endl;
  cout << "------------------------------" << endl;
  for (auto pair : huffmanCode)
  {
    cout << setw(10) << pair.first << setw(20) << pair.second << endl;
  }
  cout << "------------------------------" << endl;

  cout << "Time taken to build Huffman Tree: " << time_taken_build_tree << " milliseconds" << endl;

  string encodedString = "";
  for (char ch : text)
  {
    encodedString += huffmanCode[ch];
  }

  cout << "\nEncoded String: " << encodedString << endl;
  cout << "Time taken for encoding: " << time_taken_encoding << " milliseconds" << endl;

  start = clock();
  string decodedString = decode(root, encodedString);
  end = clock();
  double time_taken_decoding = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

  cout << "\nDecoded String: " << decodedString << endl;
  cout << "Time taken for decoding: " << time_taken_decoding << " milliseconds" << endl;

  return 0;
}
