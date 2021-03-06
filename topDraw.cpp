{
	gROOT->SetStyle("Plain");//"Pub","Plain"
	//gROOT->ProcessLine("#include <vector>");
	gStyle->SetOptStat(0);//To display the mean and RMS: SetOptStat("mr"), nemruoi, ;
	gStyle->SetOptDate(0);//display date position
	/*gStyle->SetCanvasDefH(600);//Height of canvas
	  gStyle->SetCanvasDefW(600);//Width of canvas
	  gStyle->SetCanvasDefX(0);//Position on screen
	  gStyle->SetCanvasDefY(0);*/
	gStyle->SetPalette(0);

	gStyle->SetPadLeftMargin(0.12);
	gStyle->SetPadRightMargin(0.02);
	gStyle->SetPadTopMargin(0.07);
	gStyle->SetPadBottomMargin(0.1);
	gStyle->SetPadBorderMode(0);

	gStyle->SetLabelFont(42, "XY");
	gStyle->SetLabelOffset(0.006, "XY");
	gStyle->SetLabelSize(0.04, "XY");

	gStyle->SetTitleFont(42, "XY");
	gStyle->SetTitleXOffset(1);
	//gStyle->SetTitleYOffset(1.14);

	gStyle->SetAxisColor(1, "XYZ");
	gStyle->SetTickLength(0.03, "XYZ");
	gStyle->SetNdivisions(510, "XYZ");
	gStyle->SetPadTickX(1);// To get tick marks on the opposite side of the frame
	gStyle->SetPadTickY(1);

	/*gStyle->SetFrameBorderMode(0);
	  gStyle->SetFrameBorderSize(1);
	  gStyle->SetCanvasBorderMode(0);
	  gStyle->SetGridStyle(3);
	  gStyle->SetGridWidth(1);*/

	//---------------------------------------------------

	TLatex lt1;
	lt1.SetTextAlign(12);
	lt1.SetNDC();
	lt1.SetTextFont(132);
	lt1.SetTextAngle(0);
	lt1.SetTextSize(0.065);

	TLatex lt2;
	lt2.SetTextAlign(12);
	lt2.SetNDC();
	lt2.SetTextFont(61);
	lt2.SetTextAngle(0);
	lt2.SetTextSize(0.058);

	TLatex lt3;
	lt3.SetTextAlign(12);
	lt3.SetNDC();
	lt3.SetTextAngle(0);
	lt3.SetTextFont(52);
	lt3.SetTextSize(0.045);

	TLatex lt4;
	lt4.SetTextAlign(32);
	lt4.SetNDC();
	lt4.SetTextAngle(0);
	lt4.SetTextFont(42);
	lt4.SetTextSize(0.05);
	//----------------------------------------------------


	//-----------------------------------Coordinate of CMS Simulation------------------------------------------------------------
	float x_1 = 0.12; //right top side x_1 = 0.73
	const float y_1 = 0.97; //right top side y_1 = 0.84
	float x_2 = x_1+0.095; //right top side y_2 = y_1-0.07
	float y_2 = y_1-0.005;
	//------------------------------------Coordinate of first LatexBox---------------------------------------
	float xx_1 = 0.18;
	float yy_1 = 0.83;
	//--------------------------------------Set Maximum histo_TTTT[NVar][NStep][nCh]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.98;
	float ty = 0.97;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.65;
	float ly1 = 0.54;
	float lx2 = 0.95;
	float ly2 = 0.86;

	const int StepNum = 1;//Step Num total:5
	const int nVariable = 1;//number of Variable 
	const int nChannel = 1;//total: 4 ---> Dilepton, MuEl, ElEl, MuMu.
	//int NJet[] = {4,5,6,7,8,9,10};
	//int NJet[] = {6};
	const int nMonteCal = 10;
	const int nRealData = 3;

	TH1F *histo_MonteCal[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *histo_MonteCal_final[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *histo_nRealData[StepNum][nVariable][nChannel][nRealData];
	TH1F *histo_nRealData_final[StepNum][nVariable][nChannel][nRealData];
	TH1F *histo_nRealData_gen[StepNum][nVariable][nChannel][nRealData];

	TH1F *histo_RealData[StepNum][nVariable][nChannel];
	TH1F *histo_RealData_final[StepNum][nVariable][nChannel];
	TH1F *histo_RealData_gen[StepNum][nVariable][nChannel];

	TH1F *histo_SingleTop[StepNum][nVariable][nChannel];
	TH1F *histo_Diboson[StepNum][nVariable][nChannel];
	TH1F *histo_Zr[StepNum][nVariable][nChannel];

	THStack *hs[StepNum][nVariable][nChannel];

	TH1F *histo_MC[StepNum][nVariable][nChannel];
	TH1F *histo_Ratio[StepNum][nVariable][nChannel];

	//----------------------------PUEventReweighting------------------------------

	TH1F *histo_nReweight_MonteCal[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *histo_nReweight_MonteCal_gen[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *histo_nReweight_SingleTop[StepNum][nVariable][nChannel];
	TH1F *histo_nReweight_Diboson[StepNum][nVariable][nChannel];
	TH1F *histo_nReweight_Zr[StepNum][nVariable][nChannel];
	TH1F *histo_nReweight_MC[StepNum][nVariable][nChannel];
	TH1F *histo_nReweight_Data[StepNum][nVariable][nChannel];

	//-----------------------------DYEstimation------------------------------------

	TH1F *rd_ee_in[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *rd_mm_in[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *rd_ee_out[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *rd_mm_out[StepNum][nVariable][nChannel][nMonteCal];

	TH1F *mc_ee_in[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *mc_mm_in[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *mc_ee_out[StepNum][nVariable][nChannel][nMonteCal];
	TH1F *mc_mm_out[StepNum][nVariable][nChannel][nMonteCal];

	//-----------------------------------------------------------------------------

	TCanvas *canv_[StepNum][nVariable][nChannel];
	TPad *plotpad_[StepNum][nVariable][nChannel];
	TPad *ratiopad_[StepNum][nVariable][nChannel];
	TLegend *l_[StepNum][nVariable][nChannel];

	TString PATH_samples;
	//PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	//PATH_samples = "/xrootd/store/user/yjeong/TTBarDileptonAnalyzer/TtbarDileptonAnalyzer_";//KISTI
	//PATH_samples = "/xrootd/store/user/dhkim/v808_data_dec/TtbarDileptonAnalyzer_";//KISTI
	PATH_samples = "/xrootd/store/user/yjeong/v808/v808_";//KISTI

	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	//---------------------------select one------------------------
	int StepCount = 5;
	TString Step_Cut[StepNum] = {"step>=5"};

	int ChannelNum = 1;
	int NumVar = 3;//1=Vertex, 2=lep1.Pt, 3=lep1.Eta, 4=dilep.M

	//TString Variable[nVariable] = {"nvertex","dilep.M()","njet","nbjet","pseudottbar.M()"};//

	/*TString Var_int[] = {"nvertex"};
	  TString Var_float[] = {"met"};
	  int Var_int_size = sizeof(Var_int)/sizeof(Var_int[0]);
	  int Var_float_size = sizeof(Var_float)/:sizeof(Var_float[0]);
	  int var_int[100][100];
	  float var_float[100][100];*/

	double single_cut_var[nVariable][nMonteCal]={0,};
	int step, is3lep;
	bool filtered;
	int nvertex, njet, nbjet, events;
	float met, tri, genweight, puweight, mueffweight, eleffweight, btagweight, topPtWeight, weight;

	int partonChannel, partonMode1, partonMode2, channel, lep1_pid;

	TLorentzVector* dilep = NULL;
	TLorentzVector* lep1 = NULL;
	TLorentzVector* lep2 = NULL;

	TString dycut;
	TString dyvar;
	dycut = "*(step1==1)";
	dyvar = "dilep.M()";

	TString TCut_base;
	TString weight_cut;
	TCut_base = "&&tri!=0&&filtered==1&&is3lep==2&&lep1.Pt()>20&&(abs(lep1_pid)==11||abs(lep1_pid)==13)";
	//TCut_base = "&&tri!=0&&filtered==1&&is3lep==2";

	/*TString tt_others[nChannel] = {"&&!(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1)))"};//channel = 1, 2, 3 -> Dilepton
	  TString tt_signal[nChannel] = {"&&(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1)))"};//channel = 1, 2, 3 -> Dilepton
	  TString Channel_Cut[nChannel] = {"&&channel==1||channel==2||channel==3"};
	  TString Channel_txt[nChannel] = {"Dilepton"};//-*///1||2||3

	TString tt_others[nChannel] = {"&&!(partonChannel==2 && (partonMode1==2 && partonMode2==2))"};//channel = 1 -> MuEl
	  TString tt_signal[nChannel] = {"&&(partonChannel==2 && (partonMode1==2 && partonMode2==2))"};//channel = 1 -> MuEl
	  TString Channel_Cut[nChannel] = {"&&channel==1"};
	  TString Channel_txt[nChannel] = {"e^{#pm}#mu^{#mp}"};//-*///channel_1

	/*TString tt_others[nChannel] = {"&&!(partonChannel==2 && (partonMode1==1 && partonMode2==1))"};//channel = 2 -> ElEl
	TString tt_signal[nChannel] = {"&&(partonChannel==2 && (partonMode1==1 && partonMode2==1))"};//channel = 2 -> ElEl
	TString Channel_Cut[nChannel] = {"&&channel==2"};
	TString Channel_txt[nChannel] = {"e^{#pm}e^{#mp}"};//-*///channel_2

	/*TString tt_others[nChannel] = {"&&!(partonChannel==2 && partonMode==pseudoChannel && partonMode==channel)"};//channel = 2 -> MuMu
	  TString tt_signal[nChannel] = {"&&(partonChannel==2 && partonMode==pseudoChannel && partonMode==channel)"};//channel = 2 -> MuMu
	  TString Channel_Cut[nChannel] = {"&&channel==2"};
	  TString Channel_txt[nChannel] = {"#mu^{#pm}#mu^{#mp}"};//-*///channel_3

	//**********************************************************

	/*TString Variable[nVariable] = {"nvertex"};
	  TString Ytitle[nVariable] = {"Number of Events"};
	  TString Xtitle[nVariable] = {"Number of good Vertices"};
	  int nbin[nVariable] = {50};
	  float xmin[nVariable] = {0};
	  float xmax[nVariable] = {50};
	  float ymin[nVariable] = {10};//-*/

	/*TString Variable[nVariable] = {"lep1.Pt()"};
	  TString Ytitle[nVariable] = {"Events"};
	  TString Xtitle[nVariable] = {"p_{T}^{lep} [GeV]"};
	  int nbin[nVariable] = {9};
	  int xmin[nVariable] = {20};
	  int xmax[nVariable] = {200};
	  int ymin[nVariable] = {100};//-*/

	TString Variable[nVariable] = {"lep1.Eta()"};
	TString Ytitle[nVariable] = {"Events / 0.5"};
	TString Xtitle[nVariable] = {"lepton #eta"};
	int nbin[nVariable] = {10};
	float xmin[nVariable] = {-2.5};
	float xmax[nVariable] = {2.5};
	float ymin[nVariable] = {100};//-*/

	/*TString Variable[nVariable] = {"dilep.M()"};//
	  TString Ytitle[nVariable] = {"Events / 5 GeV"};//
	  TString Xtitle[nVariable] = {"M(ll) [GeV]"};//
	  int nbin[nVariable] = {60};//
	  float xmin[nVariable] = {20};//
	  float xmax[nVariable] = {320};//
	  float ymin[nVariable] = {100};//-*/

	////////////////////////////////Get Samples/////////////////////////////////

	const int Sample_Num = 13;//=======check
	TString Sample_name[Sample_Num] = {"TT_powheg","TT_powheg","WJets","SingleTbar_tW","SingleTop_tW","ZZ","WW","WZ","DYJets","DYJets_10to50","MuonEG_Run2016","DoubleEG_Run2016","DoubleMuon_Run2016"};//===============================check

	TString Legend_Name[Sample_Num] = {"t#bar{t}-signal","t#bar{t}-others","W+Jets","Single Top","Single Top","Diboson","Diboson","Diboson","Z/#gamma^{*}#rightarrow#font[12]{l#lower[-0.4]{+}l#lower[-0.4]{#font[122]{\55}}}"};//===============================check

	TFile *tfile[Sample_Num];

	for(int i = 0; i < Sample_Num; i++){
		tfile[i] = new TFile(PATH_samples+Sample_name[i]+".root");
	}

	double tt_powheg_gen_ev = 0;
	TTree *tree[Sample_Num];
	TH1D *hnevents[Sample_Num];
	double totevents[Sample_Num];
	for(int i = 0; i < Sample_Num; i++){
		tree[i] = (TTree*)tfile[i]->Get("cattree/nom");
		hnevents[i] = (TH1D*)tfile[i]->Get("cattree/nevents");
		totevents[i] = hnevents[i]->Integral();
		tt_powheg_gen_ev = totevents[0];
		if(i!=1&&i<=10)cout<<Sample_name[i]<<": "<<totevents[i]<<endl;//except tt-others
		if(i>10)cout<<Sample_name[i]<<": "<<++totevents[i]<<endl;
		//for(int l1 = 0; l1 < Var_int_size; l1++) tree[i]->SetBranchAddress(Var_int[l1],var_int[l1]);
		//for(int l1 = 0; l1 < Var_float_size; l1++) tree[i]->SetBranchAddress(Var_float[l1],var_float[l1]);
		tree[i]->SetBranchAddress("dilep",&dilep);//TreeName,&int or &float
		tree[i]->SetBranchAddress("lep1",&lep1);
		tree[i]->SetBranchAddress("lep2",&lep2);
		tree[i]->SetBranchAddress("event",&events);
		tree[i]->SetBranchAddress("nvertex",&nvertex);
		tree[i]->SetBranchAddress("njet",&njet);
		tree[i]->SetBranchAddress("met",&met);
		tree[i]->SetBranchAddress("nbjet",&nbjet);
		tree[i]->SetBranchAddress("step",&step);
		tree[i]->SetBranchAddress("tri",&tri);
		tree[i]->SetBranchAddress("filtered",&filtered);
		tree[i]->SetBranchAddress("is3lep",&is3lep);
		tree[i]->SetBranchAddress("genweight",&genweight);
		tree[i]->SetBranchAddress("puweight",&puweight);
		tree[i]->SetBranchAddress("eleffweight",&eleffweight);
		tree[i]->SetBranchAddress("mueffweight",&mueffweight);
		tree[i]->SetBranchAddress("btagweight",&btagweight);
		tree[i]->SetBranchAddress("topPtWeight",&topPtWeight);
		tree[i]->SetBranchAddress("weight",&weight);
		tree[i]->SetBranchAddress("channel",&channel);
		tree[i]->SetBranchAddress("partonChannel",&partonChannel);
		tree[i]->SetBranchAddress("partonMode1",&partonMode1);
		tree[i]->SetBranchAddress("partonMode2",&partonMode2);
		tree[i]->SetBranchAddress("lep1_pid",&lep1_pid);
	}

	/////////////////////////////////////////////////////////////////////////////

	double MonteCal_xsec[nMonteCal] = {831.76, 831.76, 61526.7, 35.85, 35.85, 16.523, 118.7, 47.13, 6025.2, 18610};//======check

	double kMM[nRealData] = {0,};
	double kEE[nRealData] = {0,};

	double mm_Alpha_data = 0;
	double mm_N_data_in = 0, mm_N_data_out = 0;
	double mm_Alpha_mc = 0;
	double mm_N_mc_in = 0, mm_N_mc_out = 0;
	double mm_N_BGSR = 0;

	double ee_Alpha_data = 0;
	double ee_N_data_in = 0, ee_N_data_out = 0;
	double ee_Alpha_mc = 0;
	double ee_N_mc_in = 0, ee_N_mc_out = 0;
	double ee_N_BGSR = 0;

	for(int nCh = 0; nCh < nChannel; nCh++){
		for(int NVar = 0; NVar < nVariable; NVar++){
			for(int NStep = 0; NStep < StepNum; NStep++){
				float size = 0.8;
				int ttsignal_c = 2;
				int ttothers_c = 906;
				int wjets_c = 3;
				int STop_c = 42;
				int Diboson_c = 7;
				int Z_pshy_c = 4;
				int data_c = 1;

				canv_[NVar][NStep][nCh] = new TCanvas(Form("Canv_%d_%d_%d",NVar,NStep,nCh),Form(""),800,800);
				//if(NVar>0)canv_[NVar][NStep][nCh]->SetLogy();
				canv_[NVar][NStep][nCh]->RedrawAxis();
				//canv_[NVar][NStep][nCh]->GetFrame()->Draw();

				l_[NVar][NStep][nCh] = new TLegend(lx1,ly1,lx2,ly2);
				l_[NVar][NStep][nCh]->SetFillColor(0);
				l_[NVar][NStep][nCh]->SetLineColor(0);
				l_[NVar][NStep][nCh]->SetLineStyle(kSolid);
				l_[NVar][NStep][nCh]->SetLineWidth(1);
				l_[NVar][NStep][nCh]->SetFillStyle(1001);
				l_[NVar][NStep][nCh]->SetTextFont(42);
				l_[NVar][NStep][nCh]->SetTextSize(0.045);

				plotpad_[NVar][NStep][nCh] = new TPad(Form("title_%d_%d_%d",NVar,NStep,nCh),Form(""),0.02,0.3,0.98,0.98);//x1,y1,x2,y2
				ratiopad_[NVar][NStep][nCh] = new TPad(Form("ratiotitle_%d_%d_%d",NVar,NStep,nCh),Form(""),0.02,0.1,0.98,0.3);

				plotpad_[NVar][NStep][nCh]->Draw();
				ratiopad_[NVar][NStep][nCh]->Draw();
				plotpad_[NVar][NStep][nCh]->cd();

				if(NumVar == 2 || NumVar == 3 || NumVar == 4)plotpad_[NVar][NStep][nCh]->SetLogy();
				plotpad_[NVar][NStep][nCh]->RedrawAxis();

				gPad->SetBottomMargin(0);

				histo_SingleTop[NVar][NStep][nCh] = new TH1F(Form("histo_SingleTop_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_Diboson[NVar][NStep][nCh] = new TH1F(Form("histo_Diboson_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_Zr[NVar][NStep][nCh] = new TH1F(Form("histo_Zr_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				////////////////////////////////////////////DYEstimation///////////////////////////////////////

				for(int nReal = 0; nReal < nRealData; nReal++){
					rd_ee_in[NVar][NStep][nCh][nReal] = new TH1F(Form("rd_ee_in_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),60,20,320);
					tree[nReal+10]->Project(Form("rd_ee_in_%d_%d_%d_%d",NVar,NStep,nCh,nReal),dyvar,Form("channel==2 && step2 ==1")+TCut_base+dycut);
					rd_ee_out[NVar][NStep][nCh][nReal] = new TH1F(Form("rd_ee_out_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),60,20,320);
					tree[nReal+10]->Project(Form("rd_ee_out_%d_%d_%d_%d",NVar,NStep,nCh,nReal),dyvar,Form("channel==2 && step2 ==0")+TCut_base+dycut);
					rd_mm_in[NVar][NStep][nCh][nReal] = new TH1F(Form("rd_mm_in_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),60,20,320);
					tree[nReal+10]->Project(Form("rd_mm_in_%d_%d_%d_%d",NVar,NStep,nCh,nReal),dyvar,Form("channel==3 && step2 ==1")+TCut_base+dycut);
					rd_mm_out[NVar][NStep][nCh][nReal] = new TH1F(Form("rd_mm_out_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),60,20,320);
					tree[nReal+10]->Project(Form("rd_mm_out_%d_%d_%d_%d",NVar,NStep,nCh,nReal),dyvar,Form("channel==3 && step2 ==0")+TCut_base+dycut);

					mm_N_data_in += rd_mm_in[NVar][NStep][nCh][nReal]->Integral(1,60+1);
					mm_N_data_out += rd_mm_out[NVar][NStep][nCh][nReal]->Integral(1,60+1);
					ee_N_data_in += rd_ee_in[NVar][NStep][nCh][nReal]->Integral(1,60+1);
					ee_N_data_out += rd_ee_out[NVar][NStep][nCh][nReal]->Integral(1,60+1);
				}

				cout<<""<<endl;
				cout<< "mm_N_data_in: " << mm_N_data_in <<endl;
				cout<< "mm_N_data_out: " << mm_N_data_out <<endl;
				cout<< "" <<endl;
				cout<< "ee_N_data_in: " << ee_N_data_in <<endl;
				cout<< "ee_N_data_out: " << ee_N_data_out <<endl;

				mm_Alpha_data = mm_N_data_in/mm_N_data_out;
				ee_Alpha_data = ee_N_data_in/ee_N_data_out;
				cout<<""<<endl;
				cout<<"mm_Data ratio(in/out): "<<mm_Alpha_data<<endl;
				cout<<"ee_Data ratio(in/out): "<<ee_Alpha_data<<endl;

				for(int nMC = 0; nMC < nMonteCal; nMC++){
					if(nMC>=2){//Background
						mc_ee_in[NVar][NStep][nCh][nMC] = new TH1F(Form("mc_ee_in_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),60,20,320);
						tree[nMC]->Project(Form("mc_ee_in_%d_%d_%d_%d",NVar,NStep,nCh,nMC),dyvar,Form("channel==2 && step2 ==1")+TCut_base+dycut);
						mc_mm_in[NVar][NStep][nCh][nMC] = new TH1F(Form("mc_mm_in_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),60,20,320);
						tree[nMC]->Project(Form("mc_mm_in_%d_%d_%d_%d",NVar,NStep,nCh,nMC),dyvar,Form("channel==3 && step2 ==1")+TCut_base+dycut);
						mc_ee_out[NVar][NStep][nCh][nMC] = new TH1F(Form("mc_ee_out_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),60,20,320);
						tree[nMC]->Project(Form("mc_ee_out_%d_%d_%d_%d",NVar,NStep,nCh,nMC),dyvar,Form("channel==2 && step2 ==0")+TCut_base+dycut);
						mc_mm_out[NVar][NStep][nCh][nMC] = new TH1F(Form("mc_mm_out_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),60,20,320);
						tree[nMC]->Project(Form("mc_mm_out_%d_%d_%d_%d",NVar,NStep,nCh,nMC),dyvar,Form("channel==3 && step2 ==0")+TCut_base+dycut);

						mm_N_mc_in += mc_mm_in[NVar][NStep][nCh][nMC]->Integral(1,60+1);
						mm_N_mc_out += mc_mm_out[NVar][NStep][nCh][nMC]->Integral(1,60+1);
						ee_N_mc_in += mc_ee_in[NVar][NStep][nCh][nMC]->Integral(1,60+1);
						ee_N_mc_out += mc_ee_out[NVar][NStep][nCh][nMC]->Integral(1,60+1);
						kEE[nMC] += sqrt(mc_ee_in[NVar][NStep][nCh][nMC]->Integral(1,60+1)/mc_mm_in[NVar][NStep][nCh][nMC]->Integral(1,60+1));
						kMM[nMC] += sqrt(mc_mm_in[NVar][NStep][nCh][nMC]->Integral(1,60+1)/mc_ee_in[NVar][NStep][nCh][nMC]->Integral(1,60+1));
						cout<<""<<endl;
						cout<<"kEE: "<<kEE[nMC]<<" -  "<<Legend_Name[nMC] << endl;
						cout<<"kMM: "<<kMM[nMC]<<" -  "<<Legend_Name[nMC] << endl;
					}
				}

				mm_Alpha_mc = mm_N_mc_in/mm_N_mc_out;
				mm_N_BGSR = mm_Alpha_mc*(mm_N_data_out+1);
				ee_Alpha_mc = ee_N_mc_in/ee_N_mc_out;
				ee_N_BGSR = ee_Alpha_mc*(ee_N_data_out+1);
				cout<<""<<endl;
				cout<<"mm_MC ratio(in/out): "<< mm_Alpha_mc << endl;
				cout<<"ee_MC ratio(in/out): "<< ee_Alpha_mc << endl;
				cout<<""<<endl;
				cout<<"mm_N_BGSR : "<<mm_N_BGSR <<endl;
				cout<<"ee_N_BGSR : "<<ee_N_BGSR <<endl;

				//////////////////////////////////////////////////////////////////////////////////////////////////////////////

				/////////////////////////////////////////////MonteCals////////////////////////////////////////////////////////
				double MC_final = 0;
				for(int nMC = 0; nMC < nMonteCal; nMC++){
					if(nMC==0){//tt-signal (visible)
						histo_MonteCal[NVar][NStep][nCh][nMC] = new TH1F(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
						tree[nMC]->Project(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Variable[NVar],Step_Cut[NStep]+Channel_Cut[nCh]+TCut_base+tt_signal[nCh]);
						histo_MonteCal_final[NVar][NStep][nCh][nMC] = new TH1F(Form("histo_MonteCal_final_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
						tree[nMC]->Project(Form("histo_MonteCal_final_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Variable[NVar],Form("step>=5")+Channel_Cut[nCh]+TCut_base+tt_signal[nCh]);
						MC_final = histo_MonteCal_final[NVar][NStep][nCh][nMC]->GetEntries();
					}

					if(nMC==1){//tt-others
						histo_MonteCal[NVar][NStep][nCh][nMC] = new TH1F(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
						tree[nMC]->Project(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Variable[NVar],Step_Cut[NStep]+Channel_Cut[nCh]+TCut_base+tt_others[nCh]);
					}

					if(nMC>1){//etc (except tt-powheg)
						histo_MonteCal[NVar][NStep][nCh][nMC] = new TH1F(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
						tree[nMC]->Project(Form("histo_MonteCal_%d_%d_%d_%d",NVar,NStep,nCh,nMC),Variable[NVar],Step_Cut[NStep]+Channel_Cut[nCh]+TCut_base);
					}
				}

				//////////////////////////////////////////////RealData/////////////////////////////////////////////////////

				for(int nReal = 0; nReal < nRealData; nReal++){
					histo_nRealData[NVar][NStep][nCh][nReal] = new TH1F(Form("histo_nRealData_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
					tree[nReal+10]->Project(Form("histo_nRealData_%d_%d_%d_%d",NVar,NStep,nCh,nReal),Variable[NVar],Step_Cut[NStep]+Channel_Cut[nCh]+TCut_base);

					histo_nRealData_final[NVar][NStep][nCh][nReal] = new TH1F(Form("histo_nRealData_final%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
					tree[nReal+10]->Project(Form("histo_nRealData_final%d_%d_%d_%d",NVar,NStep,nCh,nReal),Variable[NVar],Form("step>=5")+Channel_Cut[nCh]+TCut_base);
					histo_nRealData_gen[NVar][NStep][nCh][nReal] = new TH1F(Form("histo_nRealData_gen%d_%d_%d_%d",NVar,NStep,nCh,nReal),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
					tree[nReal+10]->Project(Form("histo_nRealData_gen%d_%d_%d_%d",NVar,NStep,nCh,nReal),Variable[NVar],Form("step"));
				}
				///////////////////////////////////////////// x-section candidate ///////////////////////////////////////////

				//double BR = 0.6741;//theoritical value W->Hadron
				//4top->all hadrons = BR^4.
				//ttbar->all hadrons = BR^2.
				const double lumi = 35.9*1000;//pb-1
				//const double lumi = 2.22*1000;//pb-1
				cout<<""<<endl;
				cout<<"---------------------------------------"<<Channel_txt[nCh]<<", "<<Variable[NVar]<<", "<<Step_Cut[NStep]<<"-------------------------------------"<<endl;

				cout<<"lumi : "<<lumi<<" pb-1"<<endl;
				cout<<""<<endl;
				cout<<""<<endl;

				/////////////////////////////////////////////// MonteCals ///////////////////////////////////////////////////

				for(int nMC = 0; nMC < nMonteCal; nMC++){
					histo_MonteCal[NVar][NStep][nCh][nMC]->Scale(MonteCal_xsec[nMC]*lumi/totevents[nMC]);
				}

				double MonteCal_ev = 0;
				double SingleTop_ev = 0;
				double Diboson_ev = 0;
				double Zgamma_ev = 0;

				for(int nMC = 0; nMC < nMonteCal; nMC++){//singleTop, Diboson, Z-gamma
					if(nMC >= 3 && nMC <= 4){
						histo_SingleTop[NVar][NStep][nCh]->Add(histo_MonteCal[NVar][NStep][nCh][nMC]);
					}
					if(nMC >= 5 && nMC <= 7){
						histo_Diboson[NVar][NStep][nCh]->Add(histo_MonteCal[NVar][NStep][nCh][nMC]);
					}
					if( nMC >= 8 && nMC <= 9){
						histo_Zr[NVar][NStep][nCh]->Add(histo_MonteCal[NVar][NStep][nCh][nMC]);
					}
				}

				//--------------------------------------------Print-----------------------------------------------

				int Int_MonteCal[nMonteCal] = {0,};
				int Int_SingleTop = 0;
				int Int_Diboson = 0;
				int Int_Zgamma = 0;
				int total_1 = 0;
				int total_2 = 0;
				int total;
				int bkg;

				for(int nMC = 0; nMC < nMonteCal; nMC++){
					if(nMC<=2){
						MonteCal_ev = histo_MonteCal[NVar][NStep][nCh][nMC]->GetBinContent(nbin[NVar]+1);
						Int_MonteCal[nMC] = histo_MonteCal[NVar][NStep][nCh][nMC]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" yield : "<<Int_MonteCal[nMC]<<", err : "<<sqrt(MonteCal_ev)<<endl;
						total_1 += Int_MonteCal[nMC];
					}
					if(nMC==4){
						SingleTop_ev = histo_SingleTop[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Int_SingleTop = histo_SingleTop[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" yield : "<<Int_SingleTop<<", err : "<<sqrt(SingleTop_ev)<<endl;
					}
					if(nMC==6){
						Diboson_ev = histo_Diboson[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Int_Diboson = histo_Diboson[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" yield : "<<Int_Diboson<<", err : "<<sqrt(Diboson_ev)<<endl;
					}
					if(nMC==8){
						Zgamma_ev = histo_Zr[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Int_Zgamma = histo_Zr[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" yield : "<<Int_Zgamma<<", err : "<<sqrt(Zgamma_ev) <<endl;
					}
				}

				total_2 = Int_SingleTop+Int_Diboson+Int_Zgamma;
				total = total_1+total_2;
				bkg = total-Int_MonteCal[0];

				cout<<""<<endl;
				cout<<"bkg : "<<bkg<<endl;
				cout<<"total : "<<total<<endl;
				cout<<""<<endl;

				////////////////////////////////////////////////// RealData ///////////////////////////////////////////////////
				double Data_final = 0;
				double Data_gen = 0;

				histo_RealData[NVar][NStep][nCh] = new TH1F(Form("histo_RealData_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_RealData[NVar][NStep][nCh]->SetLineColor(data_c);
				histo_RealData_final[NVar][NStep][nCh] = new TH1F(Form("histo_RealData_final%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_RealData_gen[NVar][NStep][nCh] = new TH1F(Form("histo_RealData_gen%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);

				//histo_RealData[NVar][NStep][nCh]->SetLineStyle(2);

				for(int nReal = 0; nReal < nRealData; nReal++){
					histo_RealData[NVar][NStep][nCh]->Add(histo_nRealData[NVar][NStep][nCh][nReal]);
					histo_RealData_final[NVar][NStep][nCh]->Add(histo_nRealData_final[NVar][NStep][nCh][nReal]);
					histo_RealData_gen[NVar][NStep][nCh]->Add(histo_nRealData_gen[NVar][NStep][nCh][nReal]);
				}

				///////////////////////////////////////Branching Ratio/////////////////////////////
				Data_final = histo_RealData_final[NVar][NStep][nCh]->GetEntries();
				Data_gen = histo_RealData_gen[NVar][NStep][nCh]->GetEntries();
				cout<<""<<endl;
				cout<<"Data_final: "<<Data_final<<endl;
				cout<<"Data_gen: "<<Data_gen<<endl;
				cout<<"MC_final: "<<MC_final<<endl;
				cout<<""<<endl;
				cout<<"(Xsec)Cut Efficiency: "<<Data_final/tt_powheg_gen_ev<<endl;//76755950->nevt
				cout<<""<<endl;

				histo_MC[NVar][NStep][nCh] = new TH1F(Form("histo_MC_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				for(int nMC = 0; nMC < nMonteCal; nMC++){
					histo_MC[NVar][NStep][nCh]->Add(histo_MonteCal[NVar][NStep][nCh][nMC]);
				}

				histo_MC[NVar][NStep][nCh]->SetLineWidth(2);

				double nev_Data = 1;
				nev_Data = histo_RealData[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
				histo_RealData[NVar][NStep][nCh]->Scale(1/nev_Data);

				double nev_MC = 1;
				nev_MC = histo_MC[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
				histo_MC[NVar][NStep][nCh]->Scale(1/nev_MC);

				double revents = 0;
				revents += histo_RealData[NVar][NStep][nCh]->GetEntries();

				double ev = 0;
				ev = histo_RealData[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
				histo_RealData[NVar][NStep][nCh]->SetBinError(nbin[NVar]+1,sqrt(ev));
				cout<<"data : "<<revents<<endl;
				cout<<""<<endl;
				cout<<""<<endl;

				/*double ymax = 0;
				  ymax = hs[NVar][NStep][nCh]->GetMaximum();
				  hs[NVar][NStep][nCh]->SetMaximum(ymax*100);
				  hs[NVar][NStep][nCh]->SetMinimum(ymin[NVar]);
				  hs[NVar][NStep][nCh]->Draw();

				  histo_RealData[NVar][NStep][nCh]->Draw("same");
				  canv_[NVar][NStep][nCh]->Modified();

				  lt1.DrawLatex(xx_1,yy_1,Channel_txt[nCh]+"_"+Step_Cut[NStep]);
				  lt2.DrawLatex(x_1,y_1,"CMS");
				  lt3.DrawLatex(x_2,y_2,"Preliminary");
				  lt4.DrawLatex(tx,ty,"35.9 fb^{-1}, #sqrt{s} = 13 TeV");
				  l_[NVar][NStep][nCh]->Draw();*/

				const int n = histo_RealData[NVar][NStep][nCh]->GetNbinsX();//============>Variable
				double DataBin_ev[n];
				for(int i = 0; i < n; i++){
					DataBin_ev[i] = histo_RealData[NVar][NStep][nCh]->GetBinContent(i);
				}

				double MCBin_ev[n];
				for(int i = 0; i < n; i++){
					MCBin_ev[i] = histo_MC[NVar][NStep][nCh]->GetBinContent(i);
				}

				double RatioBin_ev[n];
				for(int i = 0; i < n; i++){
					RatioBin_ev[i] = DataBin_ev[i]/MCBin_ev[i];
					//cout<<"FixedRatio: "<<RatioBin_ev[i]<<",    Data: "<<DataBin_ev[i]<<",    MC: "<<MCBin_ev[i]<<endl;
					//cout<<RatioBin_ev[i]<<endl;
				}
				//cout<<""<<endl;
				//cout<<""<<endl;

				////////////////////////////////////////////PUeventReweighting///////////////////////////////////////////

				histo_nReweight_SingleTop[NVar][NStep][nCh] = new TH1F(Form("histo_nReweight_SingleTop_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_nReweight_Diboson[NVar][NStep][nCh] = new TH1F(Form("histo_nReweight_Diboson_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_nReweight_Zr[NVar][NStep][nCh] = new TH1F(Form("histo_nReweight_Zr_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);

				float PUeventReweight = 1;
				for(int tr = 0; tr < nMonteCal; tr++){
					histo_nReweight_MonteCal[NVar][NStep][nCh][tr] = new TH1F(Form("histo_nReweight_%d_%d_%d_%d",NVar,NStep,nCh,tr),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
					cout<<"Reweighted tree event, "<<Sample_name[tr]<<": "<<tree[tr]->GetEntries()<<endl;
					double OvFlow = histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->GetBinContent(nbin[NVar])+histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->GetBinContent(nbin[NVar]+1);
					for(int nev = 0; nev < tree[tr]->GetEntries(); nev++){

						if(dilep == NULL ) continue;
						if(lep1 == NULL) continue;
						if(lep2 == NULL) continue;

						tree[tr]->GetEntry(nev);

						if(NumVar == 1) if(NVar==0) {single_cut_var[NVar][tr] = nvertex;}
						if(NumVar == 2) if(NVar==0) {single_cut_var[NVar][tr] = lep1->Pt();}
						if(NumVar == 3) if(NVar==0) {single_cut_var[NVar][tr] = lep1->Eta();}
						if(NumVar == 4) if(NVar==0) {single_cut_var[NVar][tr] = dilep->M();}

						/*if(nCh==0)*/if(ChannelNum==1) if(!(channel==1)) continue;
						/*if(nCh==1)*/if(ChannelNum==2) if(!(channel==2)) continue;
						/*if(nCh==2)*/if(ChannelNum==3) if(!(channel==3)) continue;
						/*if(nCh==3)*/if(ChannelNum==4) if(!(channel==1 || channel==2 || channel==3)) continue;

						if(!(tri!=0&&filtered==1&&is3lep==2 && lep1->Pt()>20 && (abs(lep1_pid)==11 || abs(lep1_pid)==13))) continue;

						if(tr==0&&ChannelNum==1) if(!(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1)))) continue;//tt-signal
						if(tr==0&&ChannelNum==2) if(!(partonChannel==2 && (partonMode1==2 && partonMode2==2))) continue;

						if(tr==0&&ChannelNum==3) if(!(partonChannel==2 && (partonMode1==1 && partonMode2==1))) continue;
						if(tr==0&&ChannelNum==4) if(!(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1)))) continue;

						if(tr==1&&ChannelNum==1) if(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1))) continue;//tt-others
						if(tr==1&&ChannelNum==2) if(partonChannel==2 && (partonMode1==2 && partonMode2==2)) continue;
						if(tr==1&&ChannelNum==3) if(partonChannel==2 && (partonMode1==1 && partonMode2==1)) continue;
						if(tr==1&&ChannelNum==4) if(partonChannel==2 && ((partonMode1==1 && partonMode2==2) || (partonMode1==2 && partonMode2==1))) continue;

						if(StepCount==1) if(!(step>=1)) continue;
						if(StepCount==2) if(!(step>=2)) continue;
						if(StepCount==3) if(!(step>=3)) continue;
						if(StepCount==4) if(!(step>=4)) continue;
						if(StepCount==5) if(!(step>=5)) continue;

						if(ChannelNum==1) PUeventReweight = puweight*tri;
						if(ChannelNum==2 || ChannelNum==3) PUeventReweight = genweight*puweight*mueffweight*eleffweight*tri;
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->Fill(single_cut_var[NVar][tr],PUeventReweight);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetBinContent(nbin[NVar]+1,OvFlow);//overflow
					}

					if(tr == 0){//tt-signal(visible)
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineColor(ttsignal_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetFillColor(ttsignal_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineWidth(2);
					}
					if(tr == 1){//tt-others
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineColor(ttothers_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetFillColor(ttothers_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineWidth(2);
					}
					if(tr == 2){//w+jets
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineColor(wjets_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetFillColor(wjets_c);
						histo_nReweight_MonteCal[NVar][NStep][nCh][tr]->SetLineWidth(2);
					}
				}

				double Reweight_MonteCal_ev = 0;
				double Reweight_SingleTop_ev = 0;
				double Reweight_Diboson_ev = 0;
				double Reweight_Zgamma_ev = 0;
				int Reweight_Int_MonteCal[nMonteCal] = {0,};
				int Reweight_Int_SingleTop = 0;
				int Reweight_Int_Diboson = 0;
				int Reweight_Int_Zgamma = 0;

				for(int nMC = 0; nMC < nMonteCal; nMC++){
					histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]->Scale(MonteCal_xsec[nMC]*lumi/totevents[nMC]);
				}

				for(int nMC = 3; nMC < nMonteCal; nMC++){//singleTop, Diboson, Z-gamma
					if(nMC >= 3 && nMC <= 4){
						histo_nReweight_SingleTop[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]);
					}

					if(nMC >= 5 && nMC <= 7){
						histo_nReweight_Diboson[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]);
					}

					if( nMC >= 8 && nMC <= 9){
						histo_nReweight_Zr[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]);
					}
				}

				cout<<""<<endl;
				for(int nMC = 0; nMC < nMonteCal; nMC++){
					if(nMC<=2){
						Reweight_MonteCal_ev = histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]->GetBinContent(nbin[NVar]+1);
						Reweight_Int_MonteCal[nMC] = histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" Reweighted yield: "<<Reweight_Int_MonteCal[nMC]<<", err : "<<sqrt(Reweight_MonteCal_ev)<<endl;
					}
					if(nMC==4){
						Reweight_SingleTop_ev = histo_nReweight_SingleTop[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Reweight_Int_SingleTop = histo_nReweight_SingleTop[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" Reweighted yield : "<<Reweight_Int_SingleTop<<", err : "<<sqrt(Reweight_SingleTop_ev)<<endl;
					}
					if(nMC==6){
						Reweight_Diboson_ev = histo_nReweight_Diboson[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Reweight_Int_Diboson = histo_nReweight_Diboson[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" Reweighted yield : "<<Reweight_Int_Diboson<<", err : "<<sqrt(Reweight_Diboson_ev)<<endl;
					}
					if(nMC==8){
						Reweight_Zgamma_ev = histo_nReweight_Zr[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
						Reweight_Int_Zgamma = histo_nReweight_Zr[NVar][NStep][nCh]->Integral(1,nbin[NVar]+1);
						cout<<Legend_Name[nMC]<<" Reweighted yield : "<<Reweight_Int_Zgamma<<", err : "<<sqrt(Reweight_Zgamma_ev)<<endl;
					}
				}

				histo_nReweight_SingleTop[NVar][NStep][nCh]->SetLineColor(STop_c);
				histo_nReweight_SingleTop[NVar][NStep][nCh]->SetFillColor(STop_c);
				histo_nReweight_SingleTop[NVar][NStep][nCh]->SetLineWidth(2);
				histo_nReweight_Diboson[NVar][NStep][nCh]->SetLineColor(Diboson_c);
				histo_nReweight_Diboson[NVar][NStep][nCh]->SetFillColor(Diboson_c);
				histo_nReweight_Diboson[NVar][NStep][nCh]->SetLineWidth(2);
				histo_nReweight_Zr[NVar][NStep][nCh]->SetLineColor(Z_pshy_c);
				histo_nReweight_Zr[NVar][NStep][nCh]->SetFillColor(Z_pshy_c);
				histo_nReweight_Zr[NVar][NStep][nCh]->SetLineWidth(2);

				for(int nMC = 0; nMC < nMonteCal; nMC++){
					if(nMC==8)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_Zr[NVar][NStep][nCh],Legend_Name[nMC], "f");
					if(nMC==6)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_Diboson[NVar][NStep][nCh],Legend_Name[nMC], "f");
					if(nMC==4)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_SingleTop[NVar][NStep][nCh],Legend_Name[nMC], "f");
					if(nMC==2)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC],Legend_Name[nMC], "f");
					if(nMC==1)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC],Legend_Name[nMC], "f");
					if(nMC==0)l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC],Legend_Name[nMC], "f");
				}

				//---------------------------------------------------------

				histo_nReweight_Data[NVar][NStep][nCh] = new TH1F(Form("histo_nReweight_Data_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);

				for(int nReal = 0; nReal < nRealData; nReal++){
					histo_nReweight_Data[NVar][NStep][nCh]->Add(histo_nRealData[NVar][NStep][nCh][nReal]);
				}
				histo_nReweight_Data[NVar][NStep][nCh]->SetLineColor(data_c);

				double ev_Re = 0;
				ev_Re = histo_nReweight_Data[NVar][NStep][nCh]->GetBinContent(nbin[NVar]+1);
				histo_nReweight_Data[NVar][NStep][nCh]->SetBinError(nbin[NVar]+1,sqrt(ev_Re));
				cout<<"data : "<<revents<<endl;
				cout<<""<<endl;

				histo_nReweight_Data[NVar][NStep][nCh]->SetLineColor(1);
				histo_nReweight_Data[NVar][NStep][nCh]->SetLineWidth(1);
				histo_nReweight_Data[NVar][NStep][nCh]->SetMarkerStyle(20);
				histo_nReweight_Data[NVar][NStep][nCh]->SetMarkerSize(1.2);

				l_[NVar][NStep][nCh]->AddEntry(histo_nReweight_Data[NVar][NStep][nCh],"Data ", "lp");
				//--------------------------------------------------------

				plotpad_[NVar][NStep][nCh]->cd();

				hs[NVar][NStep][nCh] = new THStack(Form("hs_%d_%d_%d",NVar,NStep,nCh),Form(""));

				hs[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][0]);
				hs[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][1]);
				hs[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][2]);
				hs[NVar][NStep][nCh]->Add(histo_nReweight_SingleTop[NVar][NStep][nCh]);
				hs[NVar][NStep][nCh]->Add(histo_nReweight_Diboson[NVar][NStep][nCh]);
				hs[NVar][NStep][nCh]->Add(histo_nReweight_Zr[NVar][NStep][nCh]);

				double ymax = 0;
				ymax = histo_nReweight_Data[NVar][NStep][nCh]->GetMaximum();
				if(NumVar == 2 || NumVar == 3 || NumVar == 4)histo_nReweight_Data[NVar][NStep][nCh]->SetMaximum(ymax*1000);
				if(NumVar == 1)histo_nReweight_Data[NVar][NStep][nCh]->SetMaximum(ymax*1.3);
				histo_nReweight_Data[NVar][NStep][nCh]->GetYaxis()->SetTitle(Ytitle[NVar]);
				histo_nReweight_Data[NVar][NStep][nCh]->GetYaxis()->SetTitleSize(0.07);
				histo_nReweight_Data[NVar][NStep][nCh]->GetYaxis()->SetTitleOffset(1);
				histo_nReweight_Data[NVar][NStep][nCh]->SetMinimum(ymin[NVar]);
				histo_nReweight_Data[NVar][NStep][nCh]->Draw();
				hs[NVar][NStep][nCh]->Draw("histsame");
				histo_nReweight_Data[NVar][NStep][nCh]->Draw("esame");

				canv_[NVar][NStep][nCh]->Modified();

				//lt1.DrawLatex(xx_1,yy_1,Channel_txt[nCh]+"_"+Step_Cut[NStep]);
				lt1.DrawLatex(xx_1,yy_1,Channel_txt[nCh]);
				lt2.DrawLatex(x_1,y_1,"CMS");
				lt3.DrawLatex(x_2,y_2,"Preliminary");
				lt4.DrawLatex(tx,ty,"35.9 fb^{-1}, #sqrt{s} = 13 TeV");
				l_[NVar][NStep][nCh]->Draw();

				/////////////////////////////////////////////// Ratio plot //////////////////////////////////////////

				histo_nReweight_MC[NVar][NStep][nCh] = new TH1F(Form("histo_nReweight_MC_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				for(int nMC = 0; nMC < nMonteCal; nMC++){
					histo_nReweight_MC[NVar][NStep][nCh]->Add(histo_nReweight_MonteCal[NVar][NStep][nCh][nMC]);
				}

				histo_nReweight_MC[NVar][NStep][nCh]->SetLineWidth(2);

				histo_Ratio[NVar][NStep][nCh] = new TH1F(Form("histo_Ratio_%d_%d_%d",NVar,NStep,nCh),Form(""),nbin[NVar],xmin[NVar],xmax[NVar]);
				histo_Ratio[NVar][NStep][nCh]->Divide(histo_nReweight_Data[NVar][NStep][nCh],histo_nReweight_MC[NVar][NStep][nCh],1,1,"b");

				ratiopad_[NVar][NStep][nCh]->cd();
				gPad->SetTopMargin(0);
				gPad->SetBottomMargin(0);
				ratiopad_[NVar][NStep][nCh]->SetGridy();
				histo_Ratio[NVar][NStep][nCh]->SetMarkerStyle(20);
				histo_Ratio[NVar][NStep][nCh]->SetMarkerSize(1.2);
				histo_Ratio[NVar][NStep][nCh]->GetXaxis()->SetTitle(Xtitle[NVar]);
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->SetTitle("Data / MC");
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->SetTitleSize(0.17);
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->SetTitleOffset(0.3);
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->SetLabelSize(0.13);
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->CenterTitle();
				histo_Ratio[NVar][NStep][nCh]->GetYaxis()->SetNdivisions(6);
				histo_Ratio[NVar][NStep][nCh]->GetXaxis()->SetLabelSize(0.13);
				histo_Ratio[NVar][NStep][nCh]->GetXaxis()->SetTitleSize(0.2);
				histo_Ratio[NVar][NStep][nCh]->SetAxisRange(0.5,1.5,"y");
				histo_Ratio[NVar][NStep][nCh]->Draw("e");
				/*auto rp = new TRatioPlot(histo_MC[NVar][NStep][nCh],histo_RealData[NVar][NStep][nCh]);
				  rp->Draw();
				  canv_[NVar][NStep][nCh]->Update();*/
				canv_[NVar][NStep][nCh]->cd();
				canv_[NVar][NStep][nCh]->SaveAs(Save_dir+Variable[NVar]+"_"+Channel_txt[nCh]+"_"+Step_Cut[NStep]+".png");
				//canv_[NVar][NStep][nCh]->SaveAs(Save_dir+Variable[NVar]+"_"+Channel_txt[nCh]+"_"+Step_Cut[NStep]+".C");
			}
		}
	}
	cout<<"13 TeV"<<endl;
}
