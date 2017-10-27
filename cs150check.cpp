
/**
 * Basic unit tests for CS 150
 * @author Steve G.
 * @version Fall 2016
 * This is the implementation file.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

#include "cs150check.h"
vector<unsigned> hashes = {
    2461783841, 221872058, 252801173, 2038230476, 2357816046, 411834815, 2178152467, 484444480,
    459853714, 4285207230, 2377193715, 2250158140, 2260410100, 147055239, 3561669689, 630361335,
    4053273687, 4210494975, 3480454822, 1667862982, 1410798112, 3660825895, 38936182, 38936213,
    273747518, 352073743, 263872177, 151365337, 1044215, 588077480, 4061355816, 1576963044,
    766343230, 1579966061, 1851162952, 2141939604, 1691469304, 271224967, 2938492304, 1140328833,
    128986467, 2558523655, 1766306423, 4121946561, 676378836, 1408913679, 1965572695, 3873891415,
    1869927581, 3254864305, 263576298, 263578383, 3569117230, 2253809664, 3810528864, 274377899,
    3113868433, 154166393, 282789046, 263814409, 266190256, 4099088873, 430344797, 193495017,
    878367817, 3524088527, 1856916129, 59214191, 1138799265, 1138825305, 2090766909, 1919137006,
    3798090578, 1446712035, 3654118366, 3813793612, 3751764749, 3200575597, 3975437417, 765419971,
    2965036989, 253549912, 333512060, 2913649700, 2902194378, 990119869, 145117085, 497809330,
    960035571, 693724461, 3482673946, 969245426, 694816494, 2322394585, 2090936970, 1637836015,
    1835297257, 284646348, 1724482358, 2924828448, 1257370257, 871027827, 386608341, 832022181,
    1732704498, 3869629124, 3869629093, 255555647, 2090296245, 274543420, 1476285273, 2319663077,
    4263838765, 766344222, 1512164775, 2375063089, 2866388979, 714968174, 242846508, 1174740330,
    2453109621, 4077718839, 255921719, 2090957664, 4047220962, 448588527, 104683033, 1597016683,
    2137959708, 4048399843, 255211331, 4266351724, 3913250966, 1869859908, 2089933994, 636739710,
    2691229426, 1835297257, 1724482358, 825508424, 2725246722, 802244384, 2603768606, 4177361046,
    274530357, 281645942, 2808283326, 3607541216, 295119528, 1576963044, 2476582127, 2520737719,
    1748052890, 193490768, 713055743, 1367786999, 1954431719, 1749013591, 2090089591, 4077717787,
    3415258747, 1759110937, 3777486880, 2615744919, 282054258, 4159192017, 4231521052
};

/**
 * Global variables for scoring points.
 */
int possible = 0;
int fail = 0;
static const string UNDERLINE(70,'-');

static int allPossible = 0;
static int allFail = 0;

void _failReportDifference(const string& msg, double expected, double tolerance, double diff)
{
	ios::fmtflags f(cerr.flags());
	cerr.setf(ios::fixed);
	cerr.precision(4);
	cerr << "   X " << msg << ": expected [" << expected;;
	cerr.setf(ios::scientific);
	cerr << "] within tolerance [" << tolerance;
	cerr << "] but answer off by [" << diff;
	cerr << "]" << endl;
	cerr.flags(f);
	fail++;
}

void _successReport(const string& msg)
{
    cerr << "   + " << msg << endl;
}

void _failReport(const string& msg)
{
	cerr << "   X " << msg << endl;
	fail++;
}

void failMsg(const string& msg)
{
    possible++;
    _failReport(msg);
}

void passMsg(const string& msg) {
    possible++;
    _successReport(msg);
}

//////////// OVERLOADED VERSION OF ASSERT_EQUALS ///////////////////////
void _assertEquals(const string& msg, const string& expected, const string& actual)
{
    possible++;
    if (expected != actual)
    {
    	_failReportEquals(msg, expected, actual);
    }
    else
    	_successReport(msg + "->" + actual);
}

void _assertEquals(const string& msg, int expected, int actual)
{
    possible++;
    if (expected != actual)
    {
    	_failReportEquals(msg, expected, actual);
    }
    else
    	_successReport(msg);
}

void _assertEquals(const string&, double, double)
{
	cerr << "XXX DO NOT USE assertEquals(double, double)" << endl;
	cerr << "      USE assertDoubleEquals(double expect, double actual, double tolerance) instead." << endl;
}
void _assertEquals(const string& msg, double expected, double actual, double tolerance)
{
	_assertEquals("", msg, expected, actual, tolerance);
}

void _assertEquals(const string& xmsg, const string& msg, double expected, double actual, double tolerance)
{
    possible++;
    double diff = abs(actual - expected);
    if (diff <= tolerance)
    {
    	_successReport(xmsg + "; " + msg);
    }
    else
    {
    	_failReportDifference(xmsg + ", " + msg, expected, tolerance, diff);
    }
}

void _assertTrue(bool cond, const string& msg)
{
    possible++;
    if (!cond)
    {
    	_failReport(msg + " should be true, but is false.");
    }
    else
    	_successReport(msg);
}

void _assertFalse(bool cond, const string& msg)
{
    possible++;
    if (cond)
    {
    	_failReport(msg + " should be false, but is true.");
    }
    else
    	_successReport(msg);
}

void beginTests()
{
    cerr << "TESTING " << ASSIGNMENT << "--" << STUDENT << endl;
    cerr << UNDERLINE << endl;
    allPossible = allFail = 0;
}

void beginFunctionTest(const string& functionName)
{
	possible = fail = 0;
    cerr << "Checking function: " << functionName << " -------------------" << endl;
}

void endFunctionTest()
{
    cerr << UNDERLINE << endl << "  Tests passing "
        << (possible - fail) << "/" << possible
        << " ("
        << fixed << setprecision(0)
        << (static_cast<double>(possible - fail) / possible) * 100.0
        << "%)." << endl << endl;

    allPossible += possible;
    allFail += fail;
}

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

std::string base64_encode(const char* bytes_to_encode, size_t in_len)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--)
    {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = static_cast<unsigned char>(((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4));
            char_array_4[2] = static_cast<unsigned char>(((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6));
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4) ; i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = static_cast<unsigned char>(((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4));
        char_array_4[2] = static_cast<unsigned char>(((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6));
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';

    }

    return ret;

}

unsigned myhash(const std::string& str)
{
    unsigned hash = 5381;
    for (size_t i = 0; i < str.size(); ++i)
        hash = 33 * hash + (unsigned char)str[i];
    return hash;
}


void endTests()
{
	double percent = (static_cast<double>(allPossible - allFail) / allPossible) * 100.0;
    cerr << UNDERLINE << endl << ASSIGNMENT << ":" << STUDENT << ":ALL TESTS -- PASS "
        << (allPossible - allFail) << "/" << allPossible
        << " ("
        << fixed << setprecision(0)
        << percent
        << "%)." << endl << UNDERLINE << endl;
    if (find(hashes.begin(), hashes.end(), myhash(STUDENT)) != hashes.end())
    {
        ostringstream out;
        out << fixed << setprecision(2) << static_cast<unsigned>(time(0))
                << ":" << STUDENT << ":" << ASSIGNMENT << ":" << percent << "%";
        string coding = out.str();
        cerr << base64_encode(coding.c_str(), coding.length()) << endl;
    }
    else
    {
    	cerr << STUDENT << " NOT FOUND IN MY CS150 ROSTER." << endl;
    	cerr << "PLEASE CHECK THE VALUE YOU ASSIGNED TO STUDENT." << endl;
    }
}

//// Code from cs150io.hxx
void replaceAll(string& str, const std::string& from, const std::string& to)
{
    if(from.empty()) return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
int run();
int runIOTests(const string& testFile)
{
    beginTests();
    ifstream in;
    in.open(testFile.c_str());
    if (! in)
    {
        cerr << "Cannot find \"" << testFile << "\" with your input and output." << endl;
        return -1;
    }

    int result = 0;
    string line;
    while (getline(in, line))
    {
        string::size_type mid = line.find('|');
        if (mid == string::npos)
        {
            cerr << "Test file is not properly formed. No tests run." << endl;
            return -1;
        }
        string input = line.substr(0, mid);
        replaceAll(input, "\\n", "\n");
        string expected = line.substr(mid + 1);
        replaceAll(expected, "\\n", "\n");

        ostringstream sout;
        istringstream sin(input);

        try
        {
        	streambuf* oldIn = cin.rdbuf();
        	streambuf* oldOut = cout.rdbuf();
        	cin.rdbuf(sin.rdbuf());
        	cout.rdbuf(sout.rdbuf());
            result = run();
            cin.rdbuf(oldIn);
            cout.rdbuf(oldOut);
        }
        catch (exception& e)
        {
            cerr << " X CRASH for input " << input << ": " << e.what() << endl;
            possible++;
            fail++;
            continue;
        }

        string actual = sout.str();
        string::size_type beg = actual.find('[');
        string::size_type end = actual.find(']');

        if (beg == string::npos || end == string::npos || beg >= end)
        {
            cerr << "Test not properly formed on line: " << line << "; Tests cancelled." << endl;
            return -1;
        }
        else
        {
            actual = actual.substr(beg + 1, end - beg - 1);
        }

        assertEqualsMsg("Input of " + input, expected, actual);
    }
    allPossible = possible;
    allFail = fail;

    endTests();

    return result;
}

int ARGC = 0;
char ** ARGV = 0;

/**
 * Main file for all testing and regular running.
 * @param argc
 * @param argv
 * @return
 */
int main(int, char **)
{
	runTests();
	return 0;
}

int run()
{
    // Add your code here

    return 0;
}

string TESTFILE = "";
string ASSIGNMENT = "H13";
