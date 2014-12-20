/*   Copyright 2010 Juan Rada-Vilela

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */
#include "fuzzylite/test.h"
#include "fuzzylite/FuzzyLite.h"
#include <limits>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "fuzzylite/FunctionTerm.h"
namespace fl {


    void Test::SimpleMamdani() {
        FuzzyOperator& op = FuzzyOperator::DefaultFuzzyOperator();
        FuzzyEngine engine("simple-mamdani", op);


        fl::InputLVar* i0 = new fl::InputLVar("cpustat0");
        i0->addTerm(new fl::TriangularTerm("d0", 0.0, 0.1));
        i0->addTerm(new fl::TriangularTerm("d1", 0.1, 0.2));
        i0->addTerm(new fl::TriangularTerm("d2", 0.2, 0.3));
        i0->addTerm(new fl::TriangularTerm("d3", 0.3, 0.4));
        i0->addTerm(new fl::TriangularTerm("d4", 0.4, 0.5));
        i0->addTerm(new fl::TriangularTerm("d5", 0.5, 0.6));
        i0->addTerm(new fl::TriangularTerm("d6", 0.6, 0.7));
        i0->addTerm(new fl::TriangularTerm("d7", 0.7, 0.8));
        i0->addTerm(new fl::TriangularTerm("d8", 0.8, 0.9));
        i0->addTerm(new fl::TriangularTerm("d9", 0.9, 1.0));
        engine.addInputLVar(i0);

        fl::InputLVar* i1 = new fl::InputLVar("cpustat1");
        i1->addTerm(new fl::TriangularTerm("d0", 0.0, 0.1));
        i1->addTerm(new fl::TriangularTerm("d1", 0.1, 0.2));
        i1->addTerm(new fl::TriangularTerm("d2", 0.2, 0.3));
        i1->addTerm(new fl::TriangularTerm("d3", 0.3, 0.4));
        i1->addTerm(new fl::TriangularTerm("d4", 0.4, 0.5));
        i1->addTerm(new fl::TriangularTerm("d5", 0.5, 0.6));
        i1->addTerm(new fl::TriangularTerm("d6", 0.6, 0.7));
        i1->addTerm(new fl::TriangularTerm("d7", 0.7, 0.8));
        i1->addTerm(new fl::TriangularTerm("d8", 0.8, 0.9));
        i1->addTerm(new fl::TriangularTerm("d9", 0.9, 1.0));
        engine.addInputLVar(i1);

        fl::InputLVar* i2 = new fl::InputLVar("cpustat2");
        i2->addTerm(new fl::TriangularTerm("d0", 0.0, 0.1));
        i2->addTerm(new fl::TriangularTerm("d1", 0.1, 0.2));
        i2->addTerm(new fl::TriangularTerm("d2", 0.2, 0.3));
        i2->addTerm(new fl::TriangularTerm("d3", 0.3, 0.4));
        i2->addTerm(new fl::TriangularTerm("d4", 0.4, 0.5));
        i2->addTerm(new fl::TriangularTerm("d5", 0.5, 0.6));
        i2->addTerm(new fl::TriangularTerm("d6", 0.6, 0.7));
        i2->addTerm(new fl::TriangularTerm("d7", 0.7, 0.8));
        i2->addTerm(new fl::TriangularTerm("d8", 0.8, 0.9));
        i2->addTerm(new fl::TriangularTerm("d9", 0.9, 1.0));
        engine.addInputLVar(i2);

        fl::OutputLVar* o0 = new fl::OutputLVar("cpualloc0");
        o0->addTerm(new fl::TriangularTerm("d0", 0.0, 0.1));
        o0->addTerm(new fl::TriangularTerm("d1", 0.1, 0.2));
        o0->addTerm(new fl::TriangularTerm("d2", 0.2, 0.3));
        o0->addTerm(new fl::TriangularTerm("d3", 0.3, 0.4));
        o0->addTerm(new fl::TriangularTerm("d4", 0.4, 0.5));
        o0->addTerm(new fl::TriangularTerm("d5", 0.5, 0.6));
        o0->addTerm(new fl::TriangularTerm("d6", 0.6, 0.7));
        o0->addTerm(new fl::TriangularTerm("d7", 0.7, 0.8));
        o0->addTerm(new fl::TriangularTerm("d8", 0.8, 0.9));
        o0->addTerm(new fl::TriangularTerm("d9", 0.9, 1.0));
        engine.addOutputLVar(o0);

        fl::OutputLVar* o1 = new fl::OutputLVar("cpualloc1");
        o1->addTerm(new fl::TriangularTerm("d0", 0.0, 0.1));
        o1->addTerm(new fl::TriangularTerm("d1", 0.1, 0.2));
        o1->addTerm(new fl::TriangularTerm("d2", 0.2, 0.3));
        o1->addTerm(new fl::TriangularTerm("d3", 0.3, 0.4));
        o1->addTerm(new fl::TriangularTerm("d4", 0.4, 0.5));
        o1->addTerm(new fl::TriangularTerm("d5", 0.5, 0.6));
        o1->addTerm(new fl::TriangularTerm("d6", 0.6, 0.7));
        o1->addTerm(new fl::TriangularTerm("d7", 0.7, 0.8));
        o1->addTerm(new fl::TriangularTerm("d8", 0.8, 0.9));
        o1->addTerm(new fl::TriangularTerm("d9", 0.9, 1.0));
        engine.addOutputLVar(o1);
        FILE *ruleFile = fopen("frules.txt","r");
        char rinp[100];
        char rule1[1000];
        char rule2[1000];
        fgets(rinp,100,ruleFile);
        int q=0;
	int g=0;
        while(1)
        {

            sprintf(rule1,"if cpustat0 is d%d and cpustat1 is d%d and cpustat2 is d%d then cpualloc0 is d%d",(int)rinp[0]-48,(int)rinp[1]-48,(int)rinp[2]-48,(int)rinp[3]-48);
            sprintf(rule2,"if cpustat0 is d%d and cpustat1 is d%d and cpustat2 is d%d then cpualloc1 is d%d",(int)rinp[0]-48,(int)rinp[1]-48,(int)rinp[2]-48,(int)rinp[4]-48);
            printf("%s \n",rule1);
            printf("%s \n",rule2);
            printf("\n\n");
            fl::RuleBlock* block = new fl::RuleBlock();
            block->addRule(new fl::MamdaniRule(rule1, engine));
            block->addRule(new fl::MamdaniRule(rule2, engine));
            engine.addRuleBlock(block);
            if(!fgets(rinp,100,ruleFile))
                break;
                q++;
        }
        printf("\n%d rules created\n",q);
	system("touch /home/root/Desktop/res_vec2.txt");
	//FILE *fo=fopen("res_vec.txt","w");
	std::ofstream fout("/home/root/Desktop/res_vec2.txt");
        fl::flScalar cp=0.0,cp1=0.0,cp2=0.0;
        //for (fl::flScalar in = 0.0; in < 1.1; in += 0.1) {
         while(g<30)
         {
            cp=exec("xentop -b -i 1  | grep 'fedora2' | cut -f 17 -d ' '");   // hard coded
            i0->setInput(cp/100);
            sleep(sample_interval);
            cp1=exec("xentop -b -i 1 | grep 'fedora2'| cut -f 17 -d ' '");
            i1->setInput(cp1/100);
            sleep(sample_interval);
            cp2=exec("xentop -b -i 1 | grep 'fedora2'| cut -f 17 -d ' '");
            i2->setInput(cp2/100);
            engine.process();
            fl::flScalar out1 = o0->output().defuzzify();
            fl::flScalar out2 = o1->output().defuzzify();
            //(void)out; //Just to avoid warning when building
           // FL_LOG("cpustat0=" << cp);
           // FL_LOG("cpustat0 is " << i0->fuzzify(cp/100));
           // FL_LOG("cpustat1=" << cp1);
           // FL_LOG("cpustat1 is " << i1->fuzzify(cp1/100));
           // FL_LOG("cpustat2=" << cp2);
           // FL_LOG("cpustat2 is " << i2->fuzzify(cp2/100));
	//printf(">>>>>>%d<<<",(double)out1);		
	fout<<out1<<std::endl;
            FL_LOG("cpualloc0=" << out1);
            FL_LOG("cpualloc0 is " << o0->fuzzify(out1));
           // FL_LOG("cpualloc1=" << out2);
            //FL_LOG("cpualloc1 is " << o1->fuzzify(out2));
            FL_LOG("--");
	g++;
        }
    }

    float Test::exec(char* cmd)
    {
        FILE* pipe = popen(cmd, "r");
        if (!pipe) return -1;
        char buffer[128];
        std::string result = "";
        while(!feof(pipe))
        {
        if(fgets(buffer, 128, pipe) != NULL)
        result += buffer;
        }
        pclose(pipe);
        return atof(result.c_str());
    }

    void Test::main(int args,char** argv)
    {
        SimpleMamdani();
    }
}
