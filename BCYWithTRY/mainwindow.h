#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QList>
#include <QMainWindow>
#include <wiringPi.h>
#include <QThread>
#include <QAbstractSocket>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QDebug>
#include <mcp3004.h>
#include <ads1115.h>
#include <wiringPiSPI.h>
#include <softPwm.h>
#include <Iir.h>
#include <QtSql>
#include <QSqlDatabase>
#include <math.h>
#include <sr595.h>
#include <QDateTime>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScroller>
#include <QSqlQuery>
#include <QTimer>
#include "pi2c.h"
#include <QProcess>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDate>
#include <QPrinter>
#include <QPrintDialog>
#include <QCalendarWidget>
#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QProgressBar>
#include <QUrl>
#include <QProgressDialog>
#include <QFileInfo>
#include <QDir>
#include <QMap>
#include <QScrollArea>
#include <QStyledItemDelegate>
#include <QWidget>
#include <qcustomplot.h>
#include "hl7mllp.h"
#include <hl7socket.h>
#include "printer.h"
#include "virtual_keyboard.h"
#include <QtConcurrent/QtConcurrent>
extern int Input_Min,Input_Max,Output_Min,Output_Max,R1_Samp_Incu,After_R2_Incu,Direct_read_Incu,Read_d;
extern double Slope,Intercept,a,b,c,d,e,g,n1;
extern int keyboardWidth,keyboardHeight,screenWidth,screenHeight,virtual_x,virtual_y,LIS_connect_data,After_Clear_Data,Autocal_click,Run_Data,backdata,chk,cal_retest,multi_cal1,result,Multi_calibration,New_Stabil_val,read_wave_LED,read135,read180,Afterread135,Afterread180,Turbidity_Back,Init_Read,Calibrate_Done,read_wavenm;
extern double cur_temp,conct;
extern int Auto_cal_sno,Autocal_Gainval,Autocal_Intern_First,Autocal_Intern_Second,Autocal_NM_Change,Internal,External,Run_DW340,Run_DW405,Run_DW505,Run_DW545,Run_DW570,Run_DW630,Run_DW700,New_row,With_G,read135,read180,Afterread135,Afterread180,Turbidity_Back,Turdata,Turbidity_read_Intensity;
extern QString Autocal_String,P_Name,Calibration_Histry_TestName,Calibration_Histry_Testcode,QC1_Testname,QC2_Testname,Fromdt,Todt,msgicondata,nanometer,Restore_DC,Test_Type,ICON_PATH;
extern QString startval,clickval0,clickval1,clickval2,clickval3,clickval4,clickval5,clickval6,clickval7,clickval8,clickval9,clickval10,clickval11,clickval12;
extern int LIS_Sending_Data,check_saveBtn,Cal_His_Val,read_status,save_data_back,update_data_back,settings_mode,Loop_data,Page_change,Turbi_Cal1,Turbi_Cal2,Turbi_Cal3,Turbi_Cal4,Turbi_Cal5,Turbi_Cal6,Turbi_Cal7,Turbi_Cal8,Turbi_Sample,Turbi_cal_final,Turbi_cal_finaled,Turbi_Current_Read_Point,read_wave135 ,read_wave180,cal_retest,Afterread_wave135 ,Afterread_wave180;
extern int read_wave,read_intensity,total_read_point,current_read_point,sec_read_point,third_read_point,last_read_point;
extern int current_end_read_point,kineticruncal,calibration_check,kineticrunsamp,tworuncal,exptopn,tworunsamp,endruncal;
extern int endrunsamp,Fixed_Kinetic_Print,Kinetic_Print,testback,editback,Obj_data,data1,data2,data3,data4,data5,data6;
extern int FKCprintopt,FKSprintopt,FKQC1printopt,FKQC2printopt,KCprintopt,KSprintopt,KQC1printopt,KQC2printopt,deleteback;
extern int qcback,filterback,endqcfinish,endsampfinish,twoqcfinish,twosampfinish,kineticqcfinish,kineticsampfinish,LIS_data;
extern int tabtest,tabrecent,tabedit,tabdelete,tabqc,tabfilter,tabnumber,tabnumber2,endpointsavebtn,twopointsavebtn,kineticsavebtn;
extern int dateformat,comboIndex,datetimeset,dly,qc1retestbtn,qc2retestbtn,lagg,val,Calreteststop,QCreteststop,Samplereteststop;
extern int w340,count,w405,w505,w545,w570,w630,w700,vaalu,vaalu2,nextnumber,nextnumber3,nextnumber4;
extern int Enter,tot,load_minval,load_midval,load_maxval,retestval,line,filtwave[600],option,filtwave135[600],filtwave180[600],Afterfiltwave135[600],Afterfiltwave180[600];
extern int FrstInternval,SecInternval,ThreeInternval,FourInternval,FiveInternval,SixInternval,SevenInternval,EightInternval,NineInternval,TenInternval;
extern int EleInternval,TweInternval,ThirInternval,ForInternval,Printopt1,Printopt2,EleInternval;
extern int TwelInternval,ThirInternval,dataval,cnnt,decimalpoint,xval,PID_num,PName_num,PAge_num,calibrate;
extern int PGender_num,Pdefault,msgboxdata,Cdefault,End_qc1_opt,End_qc2_opt,Two_qc1_opt,Two_qc2_opt,Kin_qc1_opt,Kin_qc2_opt,Increament_data340,Increament_data405,Increament_data505,Increament_data545,Increament_data570,Increament_data630,Increament_data700;
extern QString Tname , batchno,concent,Calib_Abs,factor,dte,bno,conc,procode,CalibrateAbs,Fact,msgboxtext,deleteindex,Current_Connection;
extern double cur_abs,next_abs,cur1_abs,next2_abs,cur2_abs,next3_abs,cur3_abs,next4_abs;
extern double blank_val,fct,before_data;
extern std::string IPAddress ;
extern std::string PortNumber;
extern int BlankBackfunc,endsavebtn,CountBackfunc,dummyk,polycal,rec;
extern double concen,multiFact,bc_y_val,absorbance,ymin,ymax,start,incv,end,QC1,QC2,currentvl,oldvl;
class QString;
extern QString endval,text,TestName,Glu_Temp,Cal_Abs1,Cal_Abs2,Cal_Abs3,Cal_Abs4,Cal_Abs5,Cal_Abs6,Cal_Abs7,Cal_Abs8,Cal_Abs9,Cal_Abs10,ctrl1min,ctrl1max,ctrl1bno,ctrl2min,ctrl2max,ctrl2bno,Barcode_checkname,DBTestName,TestName_Show;
extern QList<QString>  unit_data;
extern QList<double> list;
extern QList<double> lit;
extern QList<QString> datefmt;
extern QList<QString> timefmt;
extern int BackBlankfunc,Objdel,nextnumber2,readingtime,sno,startvl,endvl,tem,tem1;
extern QList<QString> dat;
extern QList<QString> LotNumber;
extern QList<QString> LotNumber1;
extern QList<QString> LottNumber;
extern QString Prod_Code,Dateee,QC1Conc,QC1OD,QC2Conc,QC2OD,Unit,unit,QCMin,QCMax,Timeee,mainval1,mainval2,mainval3,LotNo,LNo,LNo1;
extern QList<QString> LottNo;
extern QList<QString> LottNo1;
extern double fact,stableval;
extern QTimer *Incubationtimer;
extern QTimer *Incubationtimer1;
extern QElapsedTimer etimer;
extern QTime countdown;
extern QVector<double>polyx,polyy;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QDateTime dateTime;

    QString date;

    QString time;

    bool b_Stop = false;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString transformPName(QString paramName);

    void Add_2nd_Phase_Parameters();

    void createTable_withQCHis();

    bool isTableExists(const QString& tableName);

    QString ParameterNameForDB(QString TestName);

    QString ParameterNameToShow(QString TestName);

    // void Clear_Patient_Data();

    // void Clear_Calibration_Histry();

    void Init_Brightness();

    void handleWave(const QString& wave);


    void Clear_QC_Data();

    void clearGraph_QC();

    void addPoint(double x, double y);

    void addPoints(double xx, double yy);

    void Blankstopbtnfunc();

    void Call_Msg_box();

    void Countstopbtnfunc();

    void plot_endqc();

    void plot_endreqc();

    void clearData();

    void plot_end();

    void plot_end_blnk();

    void plot_two_blnk();

    void plot_two();

    void plot_end_calibrate();

    void plot_two_calibrate();

    void clearGraph_end();

    void clearGraph_two();

    void clearGraph_kinetic();

    void setTarget(const QString& t);

    void startRequest(QUrl url);

    int one=0 , two=0 , three=0 , four=0 , five=0 , six =0, seven =0;

    void startCalibrationTimer(); // Expose method to start the timer


public:
    QSqlDatabase mydb;

    void connclose()
    {
        mydb.close();

    }
    bool connOpen()
    {

        mydb = QSqlDatabase :: addDatabase("QSQLITE" , "First");
        mydb.setDatabaseName("/home/pi/git/Bar_Data.db");
        if(!mydb.open())
        {
            qDebug()<<("Failed topen the Database");
            return false;
        }
        else
        {
            qDebug()<<("Connected...");
            return true;
        }
    }


signals:

    void on_one();

    void newMessage(QString);

private slots:

    uint8_t reverseBits(uint8_t byte);

    void stopMotor();

    void CreateTable_WithDifferent_AgeGrp(const QString &tableName);

    void CreateTable_Turbi_WithDifferent_AgeGrp(const QString &tableName);

    void Biochemistry_CSS();

    QString getAnyDeskID();

    void Turbidity_CSS();

    void Data_store();

    void on_Save_Btn_2_clicked();

    void on_Main_Menu_clicked();

    void on_Main_Menu_2_clicked();

    void Listout_Turbidity_Parameter();

    void Turbidity_NewCal();

    QDate calculateExpiryDate1(const QDate& currentDate1);
    QDate calculateExpiryDate2(const QDate& currentDate2);
    QDate calculateExpiryDate3(const QDate& currentDate3);
    QDate calculateExpiryDate4(const QDate& currentDate4);
    QDate calculateExpiryDate5(const QDate& currentDate5);
    QDate calculateExpiryDate6(const QDate& currentDate6);
    QDate calculateExpiryDate7(const QDate& currentDate7);
    QDate calculateExpiryDate8(const QDate& currentDate8);

    int Autocalibrate_turbi();

    void Turbidity_reading_Stop();

    void Turbidity_reading_AfterInc();

    QVector<double> calculateTrendline(const QVector<double> &xData, const QVector<double> &yData);

    double calculateRSquared(const QVector<double> &xData, const QVector<double> &yData, double slope, double intercept);

    void DisplayStatistics(const size_t n, const size_t nstar, const size_t k, const double RSS, const double R2,
                           const double R2Adj, const double SE);
    void DisplayCovCorrMatrix(const size_t k, const double sigma, const bool fixed, double **XTWXInv);

    double incbeta(double a, double b, double x);

    void displayMat(double **A, const size_t n, const size_t m);

    double **Make2DArray(const size_t rows, const size_t cols);

    void WriteCIBands(std::string filename, const double *x, const double *coefbeta, double **XTXInv,
                      const double tstudentval, const double SE, const size_t n, const size_t k) ;

    double calculatePoly(const double x, const double *a, const size_t n);

    void DisplayANOVA(const size_t nstar, const size_t k, const double TSS, const double RSS);

    double cdfFisher(const double df1, const double df2, const double x);

    void DisplayCoefs(const size_t k, const size_t nstar, const double tstudentval, const double *coefbeta, const double *serbeta);

    double cdfStudent(const double nu, const double t);

    void DisplayPolynomial(const size_t k);

    void CalculateSERRBeta(const bool fixedinter, const double SE, size_t k, double *serbeta, double **XTWXInv);

    double CalculateTValueStudent(const double nu, const double alpha);

    double invincbeta(double y,double alpha, double beta);

    double CalculateR2Adj(const double *x, const double *y, const double *a, double **Weights, const bool fixed,const size_t N, const size_t n);

    double CalculateRSS(const double *x, const double *y, const double *a, double **Weights,
                        const bool fixed, const size_t N, const size_t n);

    double CalculateTSS(const double *x, const double *y, const double *a, double **Weights,
                        const bool fixed, const size_t N, const size_t n);

    double CalculateR2COD(const double *x, const double *y, const double *a, double **Weights,
                         const bool fixed, const size_t N, const size_t n);

    void PolyFit(const double *x, double *y, const size_t n, const size_t k, const bool fixedinter,
                 const double fixedinterval, double *beta, double **Weights, double **XTWXInv);

    double **MatTrans(double **arrayd, const size_t rows, const size_t cols);

    void MatVectMul(const size_t m1, const size_t m2, double **A, double *v, double *Av);

    void cofactor(double **num, double **inverse, const size_t f);

    double determinant(double **a, const size_t k);

    void transpose(double **num, double **fac, double **inverse, const size_t r);

    double **MatMul(const size_t m1, const size_t m2, const size_t m3, double **A, double **B);

    void CalculateWeights(const double *erry, double **Weights, const size_t n,
                          const int type);

    void Polynomial();

    void Turbi_Update_Func();

        void Displaycountdowntimer();

        void Displaycountdowntimer1();
    // void resetAutoIncrement(const QString& tableName);

    void QC1_loop();

    void addColumnsToTable();

    bool isColumnExists(const QString& tableName, const QString& columnName);

    void clearGraph_multical();

    void clearGraph_Turbidity();

    void clearGraph_Turbidity_Grph();

    void clearGraph_cal();

    void  Multical_plot();

    void linearity();

    QColor interpolateColor(const QColor &startColor, const QColor &endColor, float ratio) ;

    void on_pushButton_clicked();

    void QC2_loop();

    void QC_plot_func();

    //  void paintEvent(QPaintEvent *event);

    void Calibration_Histry_Update();

    void Circle_Progress_Update();

    void fetchWaveData(int waveIndex, int blankVal);

    void setWaveLED(const QString& wave);

    bool isValidBlankVal(int blankVal);

    void handleInvalidBlankVal(int waveIndex);

    void runTest(int waveIndex);

    void runQualityCheck(const QString &wave, int sno, QLabel *label, int readWave);

    void showQualityCheckResult(const QString &wave, const QString &status, const QString &iconPath);

    int Two_cal_print_image();

    int Two_QC1_print_image();

    void handleProcessError(QProcess *process, const QString &errorMessage);

    void handleProcessError1(QProcess *process, const QString &errorMessage);

    void Call_End_QCData_Func();

    void Call_End_QCData_Func_Else();

    void Call_End_QC2Data_Func();

    void Call_End_QC2Data_Func_Else();

    void productcheck();

    void EndQC1_Func();

    void EndQC2_Func();

    void shows();

    void btn();

    void ShowTime();

    void Barcode_count_check_func();

    int readadc(int);

    void Counting();

    void endqcselect();

    void endqc_Graph();

    void endreqc_Graph();

    void twoQCsampcalc();

    void twoqc_Graph();

    void Calibration_Histry_All();

    void Barcode_read();

    void conditioncheck();

    void Pro_Code_Check();

    void Pro_Code_CheckAdd();

    void Gain340nm();

    void endcalibrate();

    void endqcrun();

    void endsample();

    void twocalibrate();

    void twoqcrun();

    void twosample();

    // void kineticcalibrate();

    // void kineticqcrun();

    //  void kineticsample();

    void Gain405nm();

    void Gain505nm();

    void Gain545nm();

    void Gain570nm();

    void Gain630nm();

    void Gain700nm();

    void ResetGainval();

    int reading1();

    void twocalcalc();

    void twosampcalc();

    void Glucose_Check();

    void test340();

    void test405();

    void test505();

    void test545();

    void test570();

    void test630();

    void test700();

    void tested();

    void endcalcalc();

    void endblankcalc();

    void endsampcalc();

    void endResampcalc();

    void plot_Reend();

    void twoblankcalc();

    void kineticblankcalc();

    void Kineticcalfirstpoint1();

    void Kineticcalfirstpoint2();

    void Kineticcalsecondpoint1();

    void Kineticcalsecondpoint2();

    void Kineticcalthirdpoint1();

    void Kineticsampfirstpoint1();

    void Kineticsampfirstpoint2();

    void Kineticsampsecondpoint1();

    void Kineticsampsecondpoint2();

    void Kineticsampthirdpoint1();

    void KineticQCsampfirstpoint1();

    void KineticQCsampfirstpoint2();

    void KineticQCsampsecondpoint1();

    void KineticQCsampsecondpoint2();

    void KineticQCsampthirdpoint1();

    void displayResult(QNetworkReply* reply);

    void plot_end_Recalibrate();

    void endRecalcalc();

    void cald();

    void cald1();

    void cald2();

    void cald3();

    void cald4();

    void Export_files();

    void CheckBarLOTMMYY();

    void on_Home_Btn_2_clicked();

    void on_Save_Btn_clicked();

    void on_Home_Btn_3_clicked();

    void on_Home_Btn_5_clicked();

    void on_Home_Btn_4_clicked();

    void on_pushButton_3_clicked();

    void temp();

    void update_func();

    void on_Load_Btn_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_12_clicked();

    void on_Setting_Btn_clicked();

    void on_Load_Btn_2_clicked();

    void on_toolButton_14_clicked();

    void on_Menu_Btn_2_clicked();

    void on_pushButton_2_clicked();

    void on_Update_Btn_clicked();

    void on_Home_Btn_7_clicked();

    void on_RunBlank_Btn_clicked();

    void on_RunSample_Btn_clicked();

    void on_RunCal_Btn_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_15_clicked();

    void on_toolButton_clicked();

    int on_toolButton_2_clicked();

    void startUpdateProcess();

    void handleProcessError(const QString &errorMessage);

    void makeExecutable(const QString &filePath);

    void Start_loop_Auto_Calibrate();

    void uiUpdateSuccess(const QString &errorMessage);

    void uiUpdateAlreadyLatest(const QString &errorMessage);

    void scheduleReboot();

    void on_toolButton_17_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_RunSample_Btn_2_clicked();

    //void on_RunSample_Btn_3_clicked();

    void on_Power_Btn_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_25_clicked();

    void on_toolButton_20_clicked();

    void on_pushButton_7_clicked();

    void on_Print_Btn_clicked();

    void on_pushButton_11_clicked();

    void on_toolButton_18_clicked();

    void on_Power_Btn_2_clicked();

    void on_RunCal_Btn_2_clicked();

    // void on_Print_Btn_2_clicked();

    //void on_Print_Btn_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_130_clicked();

    void on_Save_Btn_5_clicked();

    void on_Save_Btn_6_clicked();

    //void on_Save_Btn_7_clicked();

    void on_toolButton_3_clicked();

    void on_pushButton_131_clicked();

    void on_toolButton_19_clicked();

    void on_pushButton_134_clicked();

    void Wave_LED();

    void Wave_LED_OFF();

    void Wave_LED_340();

    void Wave_LED_405();

    void Wave_LED_505();

    void Wave_LED_545();

    void Wave_LED_570();

    void Wave_LED_630();

    void Wave_LED_700();

    void on_toolButton_22_clicked();

    void on_toolButton_23_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_Home_Btn_11_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_132_clicked();


    //Keyboard****************************

    //Keyboard...................

    void on_Patient_Name_Btn_clicked();

    void on_Patient_Age_Btn_clicked();

    void on_pushButton_224_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_118_clicked();

    void on_pushButton_119_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_120_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_207_clicked();

    void on_pushButton_213_clicked();

    void on_pushButton_210_clicked();

    void on_pushButton_212_clicked();

    void on_pushButton_208_clicked();

    void on_pushButton_214_clicked();

    void on_pushButton_209_clicked();

    void on_pushButton_211_clicked();

    void on_pushButton_137_clicked();

    void on_pushButton_138_clicked();

    void on_pushButton_140_clicked();

    void on_pushButton_141_clicked();

    void on_pushButton_147_clicked();

    void on_pushButton_143_clicked();

    void on_pushButton_145_clicked();

    void on_pushButton_144_clicked();

    void on_pushButton_146_clicked();

    void on_pushButton_201_clicked();

    void on_pushButton_215_clicked();

    void on_pushButton_236_clicked();

    void on_pushButton_234_clicked();

    void on_pushButton_238_clicked();

    void on_pushButton_232_clicked();

    void on_pushButton_237_clicked();

    void on_pushButton_233_clicked();

    void on_pushButton_235_clicked();

    void on_pushButton_160_clicked();

    void on_pushButton_161_clicked();

    void on_pushButton_163_clicked();

    void on_pushButton_221_clicked();

    void on_pushButton_194_clicked();

    void on_pushButton_191_clicked();

    void on_pushButton_193_clicked();

    void on_pushButton_192_clicked();

    void on_pushButton_195_clicked();

    void on_pushButton_196_clicked();

    void on_pushButton_204_clicked();

    void on_pushButton_172_clicked();

    void on_pushButton_173_clicked();

    void on_pushButton_174_clicked();

    void on_pushButton_175_clicked();

    void on_pushButton_176_clicked();

    void on_pushButton_177_clicked();

    void on_pushButton_178_clicked();

    void on_pushButton_179_clicked();

    void on_pushButton_184_clicked();

    void on_pushButton_181_clicked();

    void on_pushButton_183_clicked();

    void on_pushButton_180_clicked();

    void on_pushButton_188_clicked();

    void on_pushButton_205_clicked();

    void on_pushButton_216_clicked();

    void on_pushButton_206_clicked();

    void on_pushButton_186_clicked();

    void on_pushButton_217_clicked();

    void on_pushButton_187_clicked();

    void on_pushButton_218_clicked();

    void on_pushButton_219_clicked();

    void on_pushButton_220_clicked();

    void on_pushButton_185_clicked();

    void on_pushButton_182_clicked();

    void on_pushButton_133_clicked();

    void on_Stop_Btn_clicked();

    void on_pushButton_202_clicked();

    void on_ReactionType_Combo_activated(const QString );

    void on_toolButton_16_clicked();

    void on_Home_Btn_12_clicked();

    void on_pushButton_226_clicked();

    void on_Home_Btn_13_clicked();

    void on_Retest_clicked();

    void on_Retest_4_clicked();

    void on_Settings_Back_Btn_2_clicked();

    void on_pushButton_227_clicked();

    int FinalResetGainval();

    void on_lineEdit_13_returnPressed();

    int on_lineEdit_13_textChanged(const QString &arg1);

    void on_pushButton_240_clicked();

    void on_pushButton_242_clicked();

    void endqc();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_TP_QC_Check_clicked();

    void on_E_QC_Check_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_309_clicked();

    void on_pushButton_316_clicked();

    void on_Home_Btn_14_clicked();

    void on_Home_Btn_15_clicked();

    void on_Home_Btn_16_clicked();

    void on_pushButton_315_clicked();

    void on_Retest_3_clicked();

    void endreqcrun();

    void endreqc();

    void two_qcplot();

    void on_pushButton_321_clicked();

    void on_timeZoneComboBox_2_currentTextChanged(const QString &arg1);

    void Movie();

    void on_pushButton_229_clicked();

    void Autocalibrate();

    void WindowShow();

    void Stabilizing();

    void func();

    void Progress();

    void on_pushButton_200_clicked();

    void ProductCodeChoose();

    void on_pushButton_245_clicked();

    void on_ReactionType_Combo_currentTextChanged(const QString &arg1);

    void on_pushButton_256_clicked();

    void on_Stop_Btn_2_clicked();

    void on_pushButton_258_clicked();

    void on_pushButton_263_clicked();

    void on_pushButton_264_clicked();

    void on_pushButton_267_clicked();

    void on_pushButton_275_clicked();

    void on_Settings_Back_Btn_clicked();

    void on_Home_Btn_18_clicked();

    void on_Home_Btn_19_clicked();

    void on_checkBox_clicked();

    void on_pushButton_270_clicked();

    void on_pushButton_271_clicked();

    void on_toolButton_21_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_9_clicked();

    void on_pushButton_277_clicked();

    void on_pushButton_278_clicked();

    void on_pushButton_279_clicked();

    void TestCode_Checker1();

    void TestCode_Checker2();

    int on_lineEdit_42_textChanged(const QString &arg1);

    void on_EndPoint_Save_Btn_clicked();

    //void on_TwoPoint_Save_Btn_clicked();

    void on_pushButton_292_clicked();

    void on_pushButton_290_clicked();

    void on_pushButton_291_clicked();

    void on_pushButton_295_clicked();

    void on_pushButton_293_clicked();

    void on_Home_Btn_20_clicked();

    void on_pushButton_297_clicked();

    void on_pushButton_296_clicked();

    void on_pushButton_298_clicked();

    void on_Retest_5_clicked();

    void on_pushButton_299_clicked();

    void on_Home_Btn_21_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_327_clicked();

    void on_pushButton_324_clicked();

    void Barcode_ExistingCheck();

    void on_pushButton_328_clicked();

    void on_pushButton_329_clicked();

    void on_pushButton_294_clicked();

    void on_toolButton_4_clicked();

    void on_pushButton_338_clicked();

    void comboclear();

    void on_comboBox_5_activated(const QString);

    void on_Home_Btn_17_clicked();

    void on_Home_Btn_22_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_toolButton_5_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_Home_Btn_23_clicked();

    int on_EndPoint_Print_Btn_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_25_clicked();

    void on_toolButton_11_clicked();

    void on_toolButton_27_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_136_clicked();

    void nostd(const QString &NoStd);

    void on_pushButton_164_clicked();

    void on_pushButton_139_clicked();

    void on_pushButton_6_clicked();

    void clearGridLayout(QGridLayout* layout);

    QImage loadImage(const QString &filePath);

    void on_pushButton_148_clicked();

    void on_pushButton_149_clicked();

    void on_toolButton_28_clicked();

    int on_toolButton_24_clicked();

    void on_toolButton_29_clicked();

    void on_Home_Btn_24_clicked();

    int Check_for_Updates();

    int on_pushButton_331_clicked();

    void Parameter_savefunc();

    void on_toolButton_30_clicked();

    void on_pushButton_228_clicked();

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_Data_select_delete_DB_clicked();

    void on_Data_select_delete_DB_2_clicked();

    void on_pushButton_251_clicked();

    void on_pushButton_239_clicked();

    void on_pushButton_252_clicked();

    void on_pushButton_253_clicked();

    void on_Data_select_delete_DB_3_clicked();

    void on_pushButton_244_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_toolButton_32_clicked();

    int on_pushButton_332_clicked();

    void on_pushButton_249_clicked();

    void on_toolButton_33_clicked();

    void on_toolButton_34_clicked();

    void on_toolButton_35_clicked();

    void on_toolButton_36_clicked();

    int on_toolButton_37_clicked();

    int QC1_Export_func();

    int QC2_Export_func();

    void on_toolButton_31_clicked();

    void on_toolButton_38_clicked();

    void on_toolButton_39_clicked();

    void on_toolButton_40_clicked();

    void on_toolButton_41_clicked();

    void on_toolButton_42_clicked();

    int on_toolButton_47_clicked();

    int on_toolButton_48_clicked();

    bool copyDirectory(const QString &srcPath, const QString &dstPath);

    int on_pushButton_333_clicked();

    void on_toolButton_43_clicked();

    void clearDirectory(const QString &path);

    void on_toolButton_49_clicked();

    bool EjectUsbDevice(const QString &deviceName);

    QString findUsbDeviceNode();

    void Restore_database();

    void closeDatabaseConnection();

    void connectToDatabase();

    void on_comboBox_9_currentTextChanged(const QString &arg1);

    void handleDisconnectedState();

    void handleConnectedState(const QString &wifiName);

    void unblockWifi();

    void blockWifi();

    void scanWifiNetworks();

    QString getConnectedWifiName();

    void on_pushButton_150_clicked();

    int on_toolButton_44_clicked();

    void on_pushButton_254_clicked();

    void on_pushButton_248_clicked();

    void on_toolButton_45_clicked();

    void on_pushButton_250_clicked();

    void on_pushButton_261_clicked();

    void on_pushButton_260_clicked();

    void on_pushButton_255_clicked();

    void on_pushButton_259_clicked();

    void handleWave_cald(const QString &wave);

    void on_Home_Btn_6_clicked();

    void on_pushButton_18_clicked();

    void on_toolButton_50_clicked();

    int on_pushButton_16_clicked();

    void on_pushButton_222_clicked();

    void on_pushButton_230_clicked();

    void addFieldsToTable(const QString &tableName);

    void on_pushButton_262_clicked();

    void on_pushButton_265_clicked();

    void on_pushButton_266_clicked();

    void on_toolButton_51_clicked();

    void on_pushButton_17_clicked();

    void on_toolButton_52_clicked();

    void on_comboBox_19_currentTextChanged(const QString &arg1);

    void on_toolButton_53_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_231_clicked();

    void on_pushButton_151_clicked();

    int on_toolButton_55_clicked();

    void on_toolButton_56_clicked();

    void on_checkBox_3_clicked();

    void showErrorMessage(const QString &message);

    void showInfoMessage(QMessageBox *msg, const QString &message);
    void showFinalInfoMessage(QMessageBox *msg, const QString &message);

    void backupDatabase() ;

    void clearAllData();

    // void clearTable(const QString &tableName);

    // void processWavelength(int sno, QLabel *label, int wavelengthValue);

    void on_pushButton_276_clicked();

    void on_Home_Btn_25_clicked();

    void on_toolButton_57_clicked();

    void on_toolButton_61_clicked();

    void on_toolButton_63_clicked();

    void on_toolButton_58_clicked();

    void on_toolButton_60_clicked();

    void on_toolButton_64_clicked();

    void on_toolButton_59_clicked();

    void on_toolButton_62_clicked();

    void on_toolButton_65_clicked();

    void on_toolButton_66_clicked();

    void on_Stop_Btn_3_clicked();

    void on_toolButton_69_clicked();

    void on_toolButton_70_clicked();

    void on_RunCal_Btn_4_clicked();

    void on_Turbi_Runsample_Btn_clicked();

    void on_Turbi_Runsample_Btn_4_clicked();

    void on_Turbi_Runsample_Btn_3_clicked();

    void on_Cal1_TestBtn_clicked();

    int Turbidity_reading135();

    int Turbidity_reading180();

    void on_Cal2_TestBtn_clicked();

    void on_Cal3_TestBtn_clicked();

    void on_Cal4_TestBtn_clicked();

    void on_Cal5_TestBtn_clicked();

    void on_Cal6_TestBtn_clicked();

    void Turbidity_Graph_plot();

    void on_Cal7_TestBtn_clicked();

    void on_Cal8_TestBtn_clicked();

    void on_Set_Graph_Btn_clicked();

    void on_Turbi_Runsample_Btn_5_clicked();

    void on_toolButton_71_clicked();

    void on_Home_Btn_26_clicked();

    void on_toolButton_74_clicked();

    void on_pushButton_334_clicked();

    void on_Stop_Btn_4_clicked();

    void on_toolButton_73_clicked();

    void on_Update_Btn_2_clicked();

    void Data_Updation();

    void on_Home_Btn_27_clicked();

    void on_pushButton_152_clicked();

    void on_pushButton_197_clicked();

    void on_pushButton_153_clicked();

    void on_pushButton_156_clicked();

    void on_pushButton_155_clicked();

    void on_pushButton_154_clicked();

    void on_pushButton_157_clicked();

    void on_pushButton_158_clicked();

    void on_pushButton_159_clicked();

    void on_Home_Btn_28_clicked();

    void on_pushButton_280_clicked();

    void on_pushButton_223_clicked();

    void on_pushButton_281_clicked();

    void on_pushButton_246_clicked();

    void on_pushButton_283_clicked();

    void on_pushButton_225_clicked();

    void on_pushButton_282_clicked();

    void on_pushButton_243_clicked();

    void on_pushButton_247_clicked();

    void on_pushButton_162_clicked();

    void on_pushButton_284_clicked();

    void on_pushButton_165_clicked();

    void on_pushButton_166_clicked();

    void on_pushButton_285_clicked();

    void on_pushButton_167_clicked();

    void on_pushButton_171_clicked();

    void on_pushButton_198_clicked();

    void on_pushButton_305_clicked();

    void on_pushButton_169_clicked();

    void on_pushButton_168_clicked();

    void on_pushButton_170_clicked();

    void on_pushButton_300_clicked();

    void on_pushButton_306_clicked();

    void on_pushButton_307_clicked();

    void on_pushButton_313_clicked();

    void on_pushButton_311_clicked();

    void on_pushButton_317_clicked();

    void on_pushButton_308_clicked();

    void on_pushButton_314_clicked();

    void on_pushButton_310_clicked();

    void on_pushButton_312_clicked();

    void on_pushButton_199_clicked();

    void on_pushButton_319_clicked();

    void on_pushButton_318_clicked();

    void on_pushButton_320_clicked();

    void on_pushButton_323_clicked();

    void on_pushButton_322_clicked();

    void on_comboBox_20_currentTextChanged(const QString &arg1);

    void on_comboBox_21_currentTextChanged(const QString &arg1);

    void on_pushButton_330_clicked();

    void on_pushButton_135_clicked();

    void on_pushButton_336_clicked();

    void on_pushButton_335_clicked();

    void on_pushButton_339_clicked();

    void on_pushButton_337_clicked();

    void on_pushButton_342_clicked();

    void on_pushButton_345_clicked();

    void on_pushButton_343_clicked();

    void on_pushButton_346_clicked();

    void on_pushButton_344_clicked();

    void on_pushButton_347_clicked();

    void on_pushButton_348_clicked();

    void on_pushButton_351_clicked();

    void on_pushButton_349_clicked();

    void on_pushButton_352_clicked();

    void on_pushButton_350_clicked();

    void on_pushButton_353_clicked();

    void on_pushButton_356_clicked();

    void on_pushButton_359_clicked();

    void on_pushButton_357_clicked();

    void on_pushButton_360_clicked();

    void on_pushButton_358_clicked();

    void on_pushButton_361_clicked();

    void on_pushButton_326_clicked();

    int on_pushButton_341_clicked();

    void on_pushButton_354_clicked();

    void DC_Motor();

    void on_pushButton_340_clicked();

    void on_pushButton_355_clicked();

    void on_pushButton_362_clicked();

    void on_pushButton_363_clicked();

    void on_toolButton_75_clicked();

    void on_pushButton_364_clicked();

    void on_progressBar_valueChanged(int value);

    void on_pushButton_366_clicked();

    void on_pushButton_365_clicked();

    void on_pushButton_369_clicked();

    void on_pushButton_367_clicked();

    void on_Graph_Type_4_currentTextChanged(const QString &arg1);

    //void on_Turbi_Runsample_Btn_6_clicked();

    void on_Turbi_Runsample_Btn_6_clicked();

    void on_Stop_Btn_5_clicked();

    void on_Home_Btn_29_clicked();

private:

    Ui::MainWindow *ui;

    QCPCurve *newCurvesum;

    QVector<double> qv_x, qv_y;

    QVector<double> qv_xv, qv_yv;

    QTimer * timerr;

    QTimer * DCMotor_timer;

    QTimer * timer;

    QTimer * timer1;

    QPointer<QMessageBox> connectingMsg; // Declare it here


    QTimer * Start_Loop_Calibrate;

    QTimer * Progressrun;

    QMovie *moviess;

    QMovie *movies1;

    QTimer * Functionstop;

    QTimer * Starting;

    QTimer * Stabilizingg;

    QTimer * Calling;

    QTimer * CalibrateTimer;

    QTimer * FunctionrunTimer;

    QTimer * Turbi_plot_timer;

    QTimer * readtimer;

    QTimer * CircleProgress;

    QCalendarWidget *calendar ;

    QPushButton *m_button;

    QPushButton * mypushButtons;

    QVector<QPair<QPushButton*, bool>> mypushButtonsList;
    QVector<QPair<QLineEdit*, bool>> myLineEditsList;
    QVector<QPair<QStackedWidget*, int>> myStackedWidgetsList;
    QVector<QPair<QTabWidget*, int>> myTabWidgetsList;

    QLineEdit * myLineEdits;

    QString hourPattern;

    void loadFile(const QString &fileName);

    QUrl url;

    QNetworkAccessManager *manager;

    QNetworkReply *reply;

    QProgressDialog *progressDialog;

    QFile *file;

    bool httpRequestAborted;

    qint64 fileSize;

    QWidget* tabContent ;

    int _socketfd;

    HL7MLLP *sock;

    bool isConnected; // Add this line

    bool function_check;

    QProgressBar *progressBar;
};

#endif // BCMAINWINDOW_H
