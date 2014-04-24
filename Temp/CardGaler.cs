using UnityEngine;
using GameCore;
using nba;
using StreamLoad;
using System.Collections.Generic;
public class CardShowStruct{
    public int id;
    public int x;
}
public class CardGaler:MonoBehaviour{
    public string static_res_url="http://download-nba-c.mobage.cn:8200/ios/StaticData/StaticData_107_0.unity3d";
    WWW m_www;
    void Awake(){
	QualitySettings.SetQualityLevel(5);
	//NewStaticData.Instance.Init(static_data_finish);
	NLocalizer.get_single().init(GameCore.Local.Local_CN,msglist);
	m_www=new WWW(static_res_url);
    }

    void begin(){
	foreach(KeyValuePair<int,NetworkFrame.CommonCardData> _kv in NewStaticData.Instance.PlayerDataList){
	    int _anum=0;
	    switch(_kv.Value.q){
	    default:
		_anum=0;
		break;
	    case 3:
		_anum=1;
		break;
	    case 4:
	    case 5:
	    case 6:
	    case 7:
		_anum=3;
		break;
	    }
	    //	    	    if(_kv.Value.q<4){continue;}
	    for(int i=0;i<=_anum;++i){
		CardShowStruct _css=new CardShowStruct();
		_css.id=_kv.Key;
		_css.x=i;
		//		Debug.Log(_css.id+"  "+_css.x+" "+_kv.Value.n);
		m_id_list.Add(_css);
	    }
	}
        m_shower.gameObject.SetActive(true);
	//	change();
    }
    void OnGUI(){

    }
    void Update(){
	if(m_www!=null){
	    if(m_www.isDone){
		NewStaticData.Instance.Load(m_www.assetBundle.mainAsset as StaticDataObject);
		begin();
		m_www=null;
	    }
	}
	DownLoader.Instance.Update();
	if(Input.GetKeyDown(KeyCode.S)){
	    next();
	}
	if(Input.GetKeyDown(KeyCode.LeftArrow)){
	    left();
	}
	if(Input.GetKeyDown(KeyCode.RightArrow)){
	    right();
	}
	if(Input.GetKeyDown(KeyCode.P)){
	    Application.CaptureScreenshot("Card/"+m_current_file);
	}

       
	if(m_save_tick>0.0f){
	    m_save_tick-=Time.deltaTime;
	    if(m_save_tick<=0.0f){
		m_save_tick=-1.0f;
		next();
	    }
	}
    }
    void next(){
	m_index++;
	if(m_index<m_id_list.Count){
	    refresh_index();
	    Application.CaptureScreenshot("Card/"+m_current_file);
	    m_save_tick=mc_save_time;
	}else{
	    m_save_tick=-1.0f;
	}
    }
    void refresh_index()
    {
	int _id=m_id_list[m_index].id;
	int _x=m_id_list[m_index].x;
	m_current_file=_id+"_"+_x+".png";
	NetworkFrame.CommonCardData _p=NewStaticData.Instance.PlayerDataList[_id];
	m_shower.set_info(_p,(GameCore.LayoutPosition)_p.c[0],_x,GameCore.GameInfo.get_card_max_star(_p,_x),GameCore.GameInfo.get_card_max_lv(_p,_x));		
    }
    void left()
    {
	if(m_index>0)
	    {
		m_index--;
	    }
	refresh_index();
    }
    void right()
    {
	if(m_index<m_id_list.Count-1)
	    {
		m_index++;
	    }
	refresh_index();
    }
    public CardShower m_shower;
    // List<int> m_id_list=new List<int>();
    List<CardShowStruct> m_id_list=new List<CardShowStruct>();
    int m_index=-1;
    float m_save_tick=-1.0f;
    const float mc_save_time=0.1f;
    string m_current_file;
    public  TextAsset msglist;
}
