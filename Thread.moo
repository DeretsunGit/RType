<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{09F85137-3BBA-4710-A23E-B3BE4FBE0029}" Label="" LastModificationDate="1382988353" Name="Diagramme de classes_1" Objects="129" Symbols="24" Target="Analyse" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>09F85137-3BBA-4710-A23E-B3BE4FBE0029</a:ObjectID>
<a:Name>Diagramme de classes_1</a:Name>
<a:Code>Diagramme_de_classes_1</a:Code>
<a:CreationDate>1382428597</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441780</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:PackageOptionsText>[FolderOptions]

[FolderOptions\Class Diagram Objects]
GenerationCheckModel=Yes
GenerationPath=
GenerationOptions=
GenerationTasks=
GenerationTargets=
GenerationSelections=</a:PackageOptionsText>
<a:ModelOptionsText>[ModelOptions]

[ModelOptions\Cld]
CaseSensitive=No
DisplayName=Yes
EnableTrans=No
EnableRequirements=No
ShowClss=No
DeftAttr=int
DeftMthd=
DeftParm=int
DeftCont=
DomnDttp=Yes
DomnChck=No
DomnRule=No
SupportDelay=No
PreviewEditable=Yes
AutoRealize=No
DttpFullName=Yes
DeftClssAttrVisi=private
VBNetPreprocessingSymbols=
CSharpPreprocessingSymbols=

[ModelOptions\Cld\NamingOptionsTemplates]

[ModelOptions\Cld\ClssNamingOptions]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN]

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS]

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF]

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR]

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS]

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT]

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG]

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP]

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR]

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD]

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM]

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT]

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART]

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC]

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC]

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK]

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK]

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK]

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK]

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV]

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST]

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT]

[ModelOptions\Cld\ClssNamingOptions\STAT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE]

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI]

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC]

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR]

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO]

[ModelOptions\Cld\ClssNamingOptions\FILO\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=&quot;\/:*?&lt;&gt;|&quot;
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_. &quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ]

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK]

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass]

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; +-*/!=&lt;&gt;&#39;&quot;&quot;().&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Generate]

[ModelOptions\Generate\Cdm]
CheckModel=Yes
SaveLinks=Yes
NameToCode=No
Notation=2

[ModelOptions\Generate\Pdm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No
BuildTrgr=No
TablePrefix=
RefrUpdRule=RESTRICT
RefrDelRule=RESTRICT
IndxPKName=%TABLE%_PK
IndxAKName=%TABLE%_AK
IndxFKName=%REFR%_FK
IndxThreshold=
ColnFKName=%.3:PARENT%_%COLUMN%
ColnFKNameUse=No

[ModelOptions\Generate\Xsm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No</a:ModelOptionsText>
<c:ObjectLanguage>
<o:Shortcut Id="o3">
<a:ObjectID>235078D1-9EA3-4E51-AA98-9683BA1F6E04</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382428594</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382428594</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>87317290-AF03-469F-BC1E-99593F18A4AB</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:ClassDiagrams>
<o:ClassDiagram Id="o4">
<a:ObjectID>231D5014-9671-4EE0-9B67-1E956D2235FC</a:ObjectID>
<a:Name>DiagrammeClasses_1</a:Name>
<a:Code>DiagrammeClasses_1</a:Code>
<a:CreationDate>1382428597</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382441780</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\CLD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=No
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=0
Trunc Length=80
Word Length=80
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Class.IconPicture=No
Class_SymbolLayout=
Interface.IconPicture=No
Interface_SymbolLayout=
Port.IconPicture=No
Port_SymbolLayout=
ClssShowSttr=Yes
Class.Comment=No
ClssShowCntr=Yes
ClssShowAttr=Yes
ClssAttrTrun=No
ClssAttrMax=3
ClssShowMthd=Yes
ClssMthdTrun=No
ClssMthdMax=3
ClssShowInnr=Yes
IntfShowSttr=Yes
Interface.Comment=No
IntfShowAttr=Yes
IntfAttrTrun=No
IntfAttrMax=3
IntfShowMthd=Yes
IntfMthdTrun=No
IntfMthdMax=3
IntfShowCntr=Yes
IntfShowInnr=Yes
PortShowName=Yes
PortShowType=No
PortShowMult=No
AttrShowVisi=Yes
AttrVisiFmt=1
AttrShowStrn=Yes
AttrShowDttp=Yes
AttrShowDomn=No
AttrShowInit=Yes
MthdShowVisi=Yes
MthdVisiFmt=1
MthdShowStrn=Yes
MthdShowRttp=Yes
MthdShowParm=Yes
AsscShowName=No
AsscShowCntr=Yes
AsscShowRole=Yes
AsscShowOrdr=Yes
AsscShowMult=Yes
AsscMultStr=Yes
AsscShowStrn=No
GnrlShowName=No
GnrlShowStrn=Yes
GnrlShowCntr=Yes
RlzsShowName=No
RlzsShowStrn=Yes
RlzsShowCntr=Yes
DepdShowName=No
DepdShowStrn=Yes
DepdShowCntr=Yes
RqlkShowName=No
RqlkShowStrn=Yes
RqlkShowCntr=Yes

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=No
Width=2400
Height=2400
Brush color=255 255 255
Fill Color=No
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=-1

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDCLASS]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
ClassPrimaryAttributeFont=Arial,8,U
ClassPrimaryAttributeFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=233 202 131
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDINTF]
STRNFont=Arial,8,N
STRNFont color=0 0 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
CNTRFont=Arial,8,N
CNTRFont color=0 0 0
AttributesFont=Arial,8,N
AttributesFont color=0 0 0
OperationsFont=Arial,8,N
OperationsFont color=0 0 0
InnerClassifiersFont=Arial,8,N
InnerClassifiersFont color=0 0 0
LABLFont=Arial,8,N
LABLFont color=0 0 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=205 156 156
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 0 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMPORT]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
AutoAdjustToText=No
Keep aspect=No
Keep center=No
Keep size=No
Width=825
Height=800
Brush color=250 241 211
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDASSC]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
MULAFont=Arial,8,N
MULAFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\INNERLINK]
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDACLK]
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\GNRLLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RLZSLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=3 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\RQLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=1 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\DEPDLINK]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0 0 0
Line style=2
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 0 64
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0 0 0
Line style=2
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 64 0
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8500, 11000)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>259</a:PaperSource>
<c:Symbols>
<o:GeneralizationSymbol Id="o5">
<a:CreationDate>1382431883</a:CreationDate>
<a:ModificationDate>1382987765</a:ModificationDate>
<a:Rect>((-13171,-20405), (-6691,6459))</a:Rect>
<a:ListOfPoints>((-8288,-20405),(-8288,-5485),(-11574,-5485),(-11574,6459))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o7"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o8"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o9">
<a:CreationDate>1382431893</a:CreationDate>
<a:ModificationDate>1382987766</a:ModificationDate>
<a:CenterTextOffset>(3102, 4950)</a:CenterTextOffset>
<a:Rect>((7326,-19244), (16148,-11242))</a:Rect>
<a:ListOfPoints>((7326,-19244),(10556,-19244),(10556,-11242))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o6"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o10"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o11"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o12">
<a:CreationDate>1382439582</a:CreationDate>
<a:ModificationDate>1382988335</a:ModificationDate>
<a:Rect>((40449,-17706), (53631,424))</a:Rect>
<a:ListOfPoints>((53631,-16474),(43689,-16474),(43689,424))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o14"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o15"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o16">
<a:CreationDate>1382439583</a:CreationDate>
<a:ModificationDate>1382988336</a:ModificationDate>
<a:Rect>((53779,-17633), (71331,-3503))</a:Rect>
<a:ListOfPoints>((53779,-16401),(68841,-16401),(68841,-3503))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o13"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o17"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o18"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o19">
<a:CreationDate>1382439975</a:CreationDate>
<a:ModificationDate>1382513758</a:ModificationDate>
<a:Rect>((91327,-20886), (99857,8621))</a:Rect>
<a:ListOfPoints>((99857,-19654),(94567,-19654),(94567,8621))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o20"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o21"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o22"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o23">
<a:CreationDate>1382439976</a:CreationDate>
<a:ModificationDate>1382513766</a:ModificationDate>
<a:Rect>((101552,-20892), (114603,-6439))</a:Rect>
<a:ListOfPoints>((101552,-19660),(112113,-19660),(112113,-6439))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o20"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ClassSymbol Ref="o24"/>
</c:DestinationSymbol>
<c:Object>
<o:Generalization Ref="o25"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o26">
<a:CreationDate>1382441653</a:CreationDate>
<a:ModificationDate>1382987765</a:ModificationDate>
<a:Rect>((-7025,17860), (1022,26859))</a:Rect>
<a:ListOfPoints>((-7025,17860),(-7025,26859),(1022,26859))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o7"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o27"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o28"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o29">
<a:CreationDate>1382441654</a:CreationDate>
<a:ModificationDate>1382987766</a:ModificationDate>
<a:Rect>((13512,189), (19588,28313))</a:Rect>
<a:ListOfPoints>((19588,189),(19588,9026),(13512,9026),(13512,28313))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o10"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o27"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o30"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o31">
<a:CreationDate>1382441700</a:CreationDate>
<a:ModificationDate>1382988335</a:ModificationDate>
<a:Rect>((34229,5409), (50607,24685))</a:Rect>
<a:ListOfPoints>((34229,5409),(34229,24685),(50607,24685))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o14"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o32"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o33"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o34">
<a:CreationDate>1382441702</a:CreationDate>
<a:ModificationDate>1382988336</a:ModificationDate>
<a:Rect>((52649,-3306), (65628,23253))</a:Rect>
<a:ListOfPoints>((65628,-3306),(65628,8282),(52649,8282),(52649,23253))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o17"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o32"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o35"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o36">
<a:CreationDate>1382441779</a:CreationDate>
<a:ModificationDate>1382513751</a:ModificationDate>
<a:Rect>((103276,12393), (104276,26056))</a:Rect>
<a:ListOfPoints>((103776,12393),(103776,26056))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o21"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o37"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o38"/>
</c:Object>
</o:GeneralizationSymbol>
<o:GeneralizationSymbol Id="o39">
<a:CreationDate>1382441780</a:CreationDate>
<a:ModificationDate>1382513766</a:ModificationDate>
<a:Rect>((114754,-5598), (117202,24856))</a:Rect>
<a:ListOfPoints>((117202,-5598),(117202,9110),(114754,9110),(114754,24856))</a:ListOfPoints>
<a:CornerStyle>2</a:CornerStyle>
<a:ArrowStyle>7</a:ArrowStyle>
<a:LineColor>4194432</a:LineColor>
<a:DashStyle>3</a:DashStyle>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>DISPNAME 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ClassSymbol Ref="o24"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:InterfaceSymbol Ref="o37"/>
</c:DestinationSymbol>
<c:Object>
<o:Realization Ref="o40"/>
</c:Object>
</o:GeneralizationSymbol>
<o:ClassSymbol Id="o7">
<a:CreationDate>1382429587</a:CreationDate>
<a:ModificationDate>1382987765</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-23542,4489), (2452,18825))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o41"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o10">
<a:CreationDate>1382429589</a:CreationDate>
<a:ModificationDate>1382987766</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-846,-11310), (25334,2067))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o42"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o6">
<a:CreationDate>1382431862</a:CreationDate>
<a:ModificationDate>1382431862</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12636,-22679), (7838,-16021))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o43"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o14">
<a:CreationDate>1382439575</a:CreationDate>
<a:ModificationDate>1382988335</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((33095,-236), (47967,5461))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o44"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o17">
<a:CreationDate>1382439575</a:CreationDate>
<a:ModificationDate>1382988336</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((59380,-4492), (74252,1206))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o45"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o13">
<a:CreationDate>1382439576</a:CreationDate>
<a:ModificationDate>1382439576</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((52145,-18509), (57046,-14730))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o46"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o21">
<a:CreationDate>1382439916</a:CreationDate>
<a:ModificationDate>1382513751</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((83704,8317), (111862,14973))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o47"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o24">
<a:CreationDate>1382439916</a:CreationDate>
<a:ModificationDate>1382513766</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((98034,-9767), (126192,-3111))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o48"/>
</c:Object>
</o:ClassSymbol>
<o:ClassSymbol Id="o20">
<a:CreationDate>1382439917</a:CreationDate>
<a:ModificationDate>1382513756</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((99845,-22058), (105549,-18279))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>8637161</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
ClassPrimaryAttribute 0 Arial,8,U
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Class Ref="o49"/>
</c:Object>
</o:ClassSymbol>
<o:InterfaceSymbol Id="o27">
<a:CreationDate>1382441565</a:CreationDate>
<a:ModificationDate>1382987695</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-2818,20953), (13740,31131))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>128</a:LineColor>
<a:FillColor>10263757</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Interface Ref="o50"/>
</c:Object>
</o:InterfaceSymbol>
<o:InterfaceSymbol Id="o32">
<a:CreationDate>1382441669</a:CreationDate>
<a:ModificationDate>1382797027</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((48262,22064), (56830,28078))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>128</a:LineColor>
<a:FillColor>10263757</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Interface Ref="o51"/>
</c:Object>
</o:InterfaceSymbol>
<o:InterfaceSymbol Id="o37">
<a:CreationDate>1382441716</a:CreationDate>
<a:ModificationDate>1382513749</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((97128,22392), (118982,29110))</a:Rect>
<a:LineColor>128</a:LineColor>
<a:FillColor>10263757</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
CNTR 0 Arial,8,N
Attributes 0 Arial,8,N
Operations 0 Arial,8,N
InnerClassifiers 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Interface Ref="o52"/>
</c:Object>
</o:InterfaceSymbol>
</c:Symbols>
</o:ClassDiagram>
</c:ClassDiagrams>
<c:DefaultDiagram>
<o:ClassDiagram Ref="o4"/>
</c:DefaultDiagram>
<c:Classes>
<o:Class Id="o41">
<a:ObjectID>0EC9F7DB-B7B0-4444-A3D3-B318AF061513</a:ObjectID>
<a:Name>WinThread</a:Name>
<a:Code>WinThread</a:Code>
<a:CreationDate>1382429587</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987712</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o53">
<a:ObjectID>CD6E91CD-E082-4234-B549-F856515C7B87</a:ObjectID>
<a:Name>_handle</a:Name>
<a:Code>_handle</a:Code>
<a:CreationDate>1382429591</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382429631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>HANDLE</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o54">
<a:ObjectID>D9260293-5F95-4A8C-9FD2-AF36B3B2BCFF</a:ObjectID>
<a:Name>_id</a:Name>
<a:Code>_id</a:Code>
<a:CreationDate>1382429591</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382429631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>DWORD</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o55">
<a:ObjectID>CA8F5929-FB6C-49E1-8E95-0819C1937C77</a:ObjectID>
<a:Name>_launched</a:Name>
<a:Code>_launched</a:Code>
<a:CreationDate>1382987697</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987704</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>boolean</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o56">
<a:ObjectID>FB8AC10A-11B1-43C7-B7CE-8069BAEA1170</a:ObjectID>
<a:Name>WinThread</a:Name>
<a:Code>WinThread</a:Code>
<a:CreationDate>1382429635</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790773</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o57">
<a:ObjectID>1131EF09-CD93-4E63-8F3C-3C035330A249</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382429733</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790752</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o58">
<a:ObjectID>B35D6F9D-CD58-4EA9-9727-2DE047437D73</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382429733</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790788</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o59">
<a:ObjectID>8EB5BBF2-68AC-425A-8D80-D651E3ECCE26</a:ObjectID>
<a:Name>WinThread</a:Name>
<a:Code>WinThread</a:Code>
<a:CreationDate>1382790763</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790910</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o60">
<a:ObjectID>5A5B96FE-808C-4FA0-A578-54D77943FAB7</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382790802</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790834</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o61">
<a:ObjectID>D5AEA0BD-CEAC-487E-8A1E-E547CBBFDCE0</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382790802</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790834</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o62">
<a:ObjectID>D59EA018-060B-4564-B526-F6B42EE92A3A</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382790802</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790834</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o63">
<a:ObjectID>0425AF76-BD79-4B38-82F0-2242BA647864</a:ObjectID>
<a:Name>WinThread</a:Name>
<a:Code>WinThread</a:Code>
<a:CreationDate>1382790837</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790914</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o64">
<a:ObjectID>683E68BC-BDA2-4D53-8055-BC015378B481</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382790850</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790865</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o65">
<a:ObjectID>3B5A73B2-4CBB-4843-89CA-EE2CDB2DB46F</a:ObjectID>
<a:Name>WinThread</a:Name>
<a:Code>WinThread</a:Code>
<a:CreationDate>1382790878</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790919</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o66">
<a:ObjectID>7F7594F1-42C0-46DB-9470-43E6E02B41ED</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382790888</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790901</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o67">
<a:ObjectID>67B508D7-5914-42EF-AF47-48EDDD176D35</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382790888</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790901</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o68">
<a:ObjectID>93809B72-E4A9-49C7-8DD8-F8013A5EC174</a:ObjectID>
<a:Name>start</a:Name>
<a:Code>start</a:Code>
<a:CreationDate>1382439793</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456533</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o69"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o70">
<a:ObjectID>CD60EEEB-9987-429C-BE08-E7163D5D4615</a:ObjectID>
<a:Name>stop</a:Name>
<a:Code>stop</a:Code>
<a:CreationDate>1382439793</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456533</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o71"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o72">
<a:ObjectID>72DDB0D0-A9DA-421F-809A-BB7E8D801D47</a:ObjectID>
<a:Name>join</a:Name>
<a:Code>join</a:Code>
<a:CreationDate>1382439793</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456533</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o73"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o74">
<a:ObjectID>7C8A362A-6E5A-4CCA-B41F-A40C064AF2E5</a:ObjectID>
<a:Name>tryJoin</a:Name>
<a:Code>tryJoin</a:Code>
<a:CreationDate>1382790647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790647</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o75"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o76">
<a:ObjectID>81C2C312-99A2-4273-82FE-6FD787707783</a:ObjectID>
<a:Name>timedJoin</a:Name>
<a:Code>timedJoin</a:Code>
<a:CreationDate>1382790647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790647</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o77">
<a:ObjectID>338880AB-D061-468B-8E22-D09F70BBDC75</a:ObjectID>
<a:Name>msec</a:Name>
<a:Code>msec</a:Code>
<a:CreationDate>1382790647</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790647</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o78"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o79">
<a:ObjectID>9434FF63-086D-4C76-9979-5D901AFED627</a:ObjectID>
<a:Name>isLaunched</a:Name>
<a:Code>isLaunched</a:Code>
<a:CreationDate>1382987710</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987710</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o80"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o42">
<a:ObjectID>765FB5AC-066E-4484-BB38-A322D965C838</a:ObjectID>
<a:Name>UnixThread</a:Name>
<a:Code>UnixThread</a:Code>
<a:CreationDate>1382429589</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987755</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o81">
<a:ObjectID>395163B4-4187-4569-BE0B-0A3B13D3849B</a:ObjectID>
<a:Name>_th</a:Name>
<a:Code>_th</a:Code>
<a:CreationDate>1382431733</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987744</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>pthread_t</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
<o:Attribute Id="o82">
<a:ObjectID>A099FFA8-43F0-40A3-A7CC-486B0C1DED60</a:ObjectID>
<a:Name>_launched</a:Name>
<a:Code>_launched</a:Code>
<a:CreationDate>1382987712</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987720</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>boolean</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o83">
<a:ObjectID>114EA965-308E-43ED-94C5-CB191D373DFF</a:ObjectID>
<a:Name>UnixThread</a:Name>
<a:Code>UnixThread</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790998</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o84">
<a:ObjectID>FF848021-92E4-4A31-ABF5-E5D2E11F903B</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o85">
<a:ObjectID>74BAFC0D-A85B-46CB-9E15-50BAE4C16EF2</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o86">
<a:ObjectID>4E5E4FFF-98F0-4878-818C-1A29EDCF9706</a:ObjectID>
<a:Name>UnixThread</a:Name>
<a:Code>UnixThread</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790998</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o87">
<a:ObjectID>C926DF99-6E17-40A4-869D-7B5322F4FE25</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o88">
<a:ObjectID>DC77383D-4BCF-4052-8397-9F010FE55109</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o89">
<a:ObjectID>FDB183D5-A9CB-4FE9-89B1-8EBE118532F8</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o90">
<a:ObjectID>982491C4-C19F-4C32-9222-1511B58A0C63</a:ObjectID>
<a:Name>UnixThread</a:Name>
<a:Code>UnixThread</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790998</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o91">
<a:ObjectID>7713C157-787C-4937-BF6E-9BB452C6D7C7</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o92">
<a:ObjectID>751C6800-28A5-4F19-9489-FA39694EA98C</a:ObjectID>
<a:Name>UnixThread</a:Name>
<a:Code>UnixThread</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790998</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o93">
<a:ObjectID>A43161AA-254A-4696-8333-F49294BCE9C0</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o94">
<a:ObjectID>56F2AE4E-97CB-43BF-B714-DFD9F79480AB</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382790968</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790978</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o95">
<a:ObjectID>F4A4B905-979A-4546-9FFD-1C78830EE922</a:ObjectID>
<a:Name>start</a:Name>
<a:Code>start</a:Code>
<a:CreationDate>1382456554</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456554</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o69"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o96">
<a:ObjectID>1EEC4D4E-CE0B-47F0-985A-7A623EECD792</a:ObjectID>
<a:Name>stop</a:Name>
<a:Code>stop</a:Code>
<a:CreationDate>1382456554</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456554</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o71"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o97">
<a:ObjectID>189652AA-FDAC-435F-881D-61556C803CAC</a:ObjectID>
<a:Name>join</a:Name>
<a:Code>join</a:Code>
<a:CreationDate>1382456554</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456554</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o73"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o98">
<a:ObjectID>8B724113-374F-4C33-97DA-191C6465ED51</a:ObjectID>
<a:Name>tryJoin</a:Name>
<a:Code>tryJoin</a:Code>
<a:CreationDate>1382987751</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987751</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o75"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o99">
<a:ObjectID>04108D55-63AE-40F0-9613-5FFCAB0E7BC6</a:ObjectID>
<a:Name>timedJoin</a:Name>
<a:Code>timedJoin</a:Code>
<a:CreationDate>1382987751</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987751</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o100">
<a:ObjectID>C1471466-649D-4975-8275-E97572F0F44E</a:ObjectID>
<a:Name>msec</a:Name>
<a:Code>msec</a:Code>
<a:CreationDate>1382987751</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987751</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o78"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o101">
<a:ObjectID>39EB5242-6BB5-479A-BE70-38199E8495B3</a:ObjectID>
<a:Name>isLaunched</a:Name>
<a:Code>isLaunched</a:Code>
<a:CreationDate>1382987751</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987751</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o80"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o43">
<a:ObjectID>83BB20E0-C631-472F-95AA-0B1960050AFD</a:ObjectID>
<a:Name>Thread</a:Name>
<a:Code>Thread</a:Code>
<a:CreationDate>1382431862</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o102">
<a:ObjectID>C6BC4793-0B78-482B-A392-7BAF5F304192</a:ObjectID>
<a:Name>Thread</a:Name>
<a:Code>Thread</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o103">
<a:ObjectID>82FEF53B-BB20-4049-BDAF-7922157B8AC2</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
<o:Parameter Id="o104">
<a:ObjectID>BEBE469A-54CE-4BA4-B9B9-D2081309675F</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
<a:ParameterType>I</a:ParameterType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o105">
<a:ObjectID>51D1ECBF-AF9A-410E-AA6F-E33F289102E9</a:ObjectID>
<a:Name>Thread</a:Name>
<a:Code>Thread</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o106">
<a:ObjectID>FCC86420-F96A-4E45-BAC7-BBDDE128F7C5</a:ObjectID>
<a:Name>o</a:Name>
<a:Code>o</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Obj</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o107">
<a:ObjectID>8C144EB1-18A9-4599-AE44-49877C14CB06</a:ObjectID>
<a:Name>m</a:Name>
<a:Code>m</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>MthdPtr</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o108">
<a:ObjectID>47246737-D15D-43D8-A73B-38920DE5DE2A</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o109">
<a:ObjectID>8BC1B725-A83C-4087-9152-11EBDB313DEB</a:ObjectID>
<a:Name>Thread</a:Name>
<a:Code>Thread</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o110">
<a:ObjectID>0C7544A3-7A38-46FD-84A0-6A2930EF226E</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o111">
<a:ObjectID>959D4398-FB02-4C44-89C0-809F63807575</a:ObjectID>
<a:Name>Thread</a:Name>
<a:Code>Thread</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>template</a:Stereotype>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o112">
<a:ObjectID>3A85CC64-1BBA-4F4C-88CF-2D63ECEAFD3D</a:ObjectID>
<a:Name>c</a:Name>
<a:Code>c</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Callable</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o113">
<a:ObjectID>1FD0EE68-C0EC-4B1E-BAF4-561296526550</a:ObjectID>
<a:Name>p</a:Name>
<a:Code>p</a:Code>
<a:CreationDate>1382791065</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382791081</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Param</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o44">
<a:ObjectID>D0695D6C-3F68-4219-A2FB-33AD98BF9611</a:ObjectID>
<a:Name>WinMutex</a:Name>
<a:Code>WinMutex</a:Code>
<a:CreationDate>1382439575</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988349</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o114">
<a:ObjectID>16F286DB-C40E-44C6-9FCE-DD33AC14C078</a:ObjectID>
<a:Name>_section</a:Name>
<a:Code>_section</a:Code>
<a:CreationDate>1382439659</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439683</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>CRITICAL_SECTION</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o115">
<a:ObjectID>C66634EC-3202-41FC-8496-10C2792CCCF2</a:ObjectID>
<a:Name>lock</a:Name>
<a:Code>lock</a:Code>
<a:CreationDate>1382456589</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o116"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o117">
<a:ObjectID>898EC243-6B6A-4B88-91BC-E46A9D15FAD3</a:ObjectID>
<a:Name>unlock</a:Name>
<a:Code>unlock</a:Code>
<a:CreationDate>1382456589</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o118"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o119">
<a:ObjectID>6C2D86C4-AAB7-4C1A-BEC8-0E05397B0442</a:ObjectID>
<a:Name>trylock</a:Name>
<a:Code>trylock</a:Code>
<a:CreationDate>1382456589</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o120"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o45">
<a:ObjectID>DAC38483-E2FD-4889-8040-58AC7BD3CE03</a:ObjectID>
<a:Name>UnixMutex</a:Name>
<a:Code>UnixMutex</a:Code>
<a:CreationDate>1382439575</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988353</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o121">
<a:ObjectID>60D45E01-E98B-448D-92D0-01B0A4E83F89</a:ObjectID>
<a:Name>_mutex</a:Name>
<a:Code>_mutex</a:Code>
<a:CreationDate>1382439865</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439894</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>pthread_mutex_t</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o122">
<a:ObjectID>9DFD5C8D-9AD8-4695-9FD4-568B8603AC3A</a:ObjectID>
<a:Name>lock</a:Name>
<a:Code>lock</a:Code>
<a:CreationDate>1382456604</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o116"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o123">
<a:ObjectID>75016349-7BF0-4353-BE74-50B3E4EBE9C3</a:ObjectID>
<a:Name>unlock</a:Name>
<a:Code>unlock</a:Code>
<a:CreationDate>1382456604</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>void</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o118"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o124">
<a:ObjectID>E99DB810-209C-4739-88EB-175A051ACBE4</a:ObjectID>
<a:Name>trylock</a:Name>
<a:Code>trylock</a:Code>
<a:CreationDate>1382456604</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o120"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o46">
<a:ObjectID>E84CDF07-8056-4C60-BC0A-A89DECC366B7</a:ObjectID>
<a:Name>Mutex</a:Name>
<a:Code>Mutex</a:Code>
<a:CreationDate>1382439576</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988259</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o125">
<a:ObjectID>8AA74B4A-83AD-4761-A07C-EA5162D6726C</a:ObjectID>
<a:Name>Mutex</a:Name>
<a:Code>Mutex</a:Code>
<a:CreationDate>1382988253</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988259</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o47">
<a:ObjectID>B3B94630-5DC9-49B6-989D-1A3B6DCEA795</a:ObjectID>
<a:Name>WinCondVar</a:Name>
<a:Code>WinCondVar</a:Code>
<a:CreationDate>1382439916</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988280</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o126">
<a:ObjectID>BF5ABEC4-16DE-4EAF-BE25-8BF78E9CCB16</a:ObjectID>
<a:Name>_condVar</a:Name>
<a:Code>_condVar</a:Code>
<a:CreationDate>1382440200</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440242</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>CONDITIONAL_VARIABLE</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o127">
<a:ObjectID>3C9E563F-6EF3-49C9-8D5F-2FE446694734</a:ObjectID>
<a:Name>wait</a:Name>
<a:Code>wait</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o128">
<a:ObjectID>A2AA1F52-01CA-4F84-9637-3DCF1FA27BD3</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o129"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o130">
<a:ObjectID>101B1CD8-5302-405E-80DD-BA0C1631574F</a:ObjectID>
<a:Name>signal</a:Name>
<a:Code>signal</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o131"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o132">
<a:ObjectID>8FF2AACC-738D-4A12-996B-8D0564BDADB9</a:ObjectID>
<a:Name>broadcast</a:Name>
<a:Code>broadcast</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o133"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o134">
<a:ObjectID>7FD172DB-3135-439D-9E82-95F42AA4152D</a:ObjectID>
<a:Name>timedWait</a:Name>
<a:Code>timedWait</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o135">
<a:ObjectID>6B94FFC5-B70A-4A1E-BB86-B6B4BBFC4952</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o136">
<a:ObjectID>DD94C84E-FF5A-42FD-8088-3344694FDC26</a:ObjectID>
<a:Name>usec</a:Name>
<a:Code>usec</a:Code>
<a:CreationDate>1382456618</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456619</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o137"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o48">
<a:ObjectID>B2B2EE74-57A7-4C91-952B-5A61B68646A9</a:ObjectID>
<a:Name>UnixCondVar</a:Name>
<a:Code>UnixCondVar</a:Code>
<a:CreationDate>1382439916</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988287</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Attributes>
<o:Attribute Id="o138">
<a:ObjectID>BBB2926F-D086-4E0D-AF83-0712F9BAEBFC</a:ObjectID>
<a:Name>_condVar</a:Name>
<a:Code>_condVar</a:Code>
<a:CreationDate>1382440244</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382440272</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:DataType>pthread_cond_t</a:DataType>
<a:Attribute.Visibility>-</a:Attribute.Visibility>
</o:Attribute>
</c:Attributes>
<c:Operations>
<o:Operation Id="o139">
<a:ObjectID>E5D9AC48-81E0-4FFA-9024-C3AF199BAFF6</a:ObjectID>
<a:Name>wait</a:Name>
<a:Code>wait</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o140">
<a:ObjectID>80886FCD-DA1D-4CB0-B71F-0708A8DBC55A</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o129"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o141">
<a:ObjectID>CDB579AA-147A-4632-B018-13244C50B782</a:ObjectID>
<a:Name>signal</a:Name>
<a:Code>signal</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o131"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o142">
<a:ObjectID>24C72F83-1F08-45E1-B664-BF2BC81DBC6B</a:ObjectID>
<a:Name>broadcast</a:Name>
<a:Code>broadcast</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:InfluentObject>
<o:Operation Ref="o133"/>
</c:InfluentObject>
</o:Operation>
<o:Operation Id="o143">
<a:ObjectID>07FE0A5E-7218-44DE-94E4-32B490D21B22</a:ObjectID>
<a:Name>timedWait</a:Name>
<a:Code>timedWait</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>Implement</a:Stereotype>
<a:ReturnType>boolean</a:ReturnType>
<a:Automatic>1</a:Automatic>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o144">
<a:ObjectID>E2EF6713-1179-4D29-B9AB-7590B956D1EF</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o145">
<a:ObjectID>4EFFBD90-1842-4C22-8522-F36440564B7E</a:ObjectID>
<a:Name>usec</a:Name>
<a:Code>usec</a:Code>
<a:CreationDate>1382456630</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382456631</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
<c:InfluentObject>
<o:Operation Ref="o137"/>
</c:InfluentObject>
</o:Operation>
</c:Operations>
</o:Class>
<o:Class Id="o49">
<a:ObjectID>504BDD50-CE46-4359-8B10-E00D582443B4</a:ObjectID>
<a:Name>CondVar</a:Name>
<a:Code>CondVar</a:Code>
<a:CreationDate>1382439917</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988295</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<c:Operations>
<o:Operation Id="o146">
<a:ObjectID>7459C6C9-99E5-4597-8956-5D700CB00732</a:ObjectID>
<a:Name>CondVar</a:Name>
<a:Code>CondVar</a:Code>
<a:CreationDate>1382988291</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382988295</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Class>
</c:Classes>
<c:Interfaces>
<o:Interface Id="o50">
<a:ObjectID>403333B7-4E4C-40F2-A72A-E7ACE1AEA640</a:ObjectID>
<a:Name>IThread</a:Name>
<a:Code>IThread</a:Code>
<a:CreationDate>1382441565</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382987690</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>interface</a:Stereotype>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Operations>
<o:Operation Id="o69">
<a:ObjectID>DDC71322-3068-43B8-BB6C-CD98EE1A4DD7</a:ObjectID>
<a:Name>start</a:Name>
<a:Code>start</a:Code>
<a:CreationDate>1382441621</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456555</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o71">
<a:ObjectID>49FB77E8-2BD9-4F9F-90D8-2E018735E450</a:ObjectID>
<a:Name>stop</a:Name>
<a:Code>stop</a:Code>
<a:CreationDate>1382441621</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456555</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o73">
<a:ObjectID>E78103B9-FA77-42E5-8622-0BEA39CB2EDC</a:ObjectID>
<a:Name>join</a:Name>
<a:Code>join</a:Code>
<a:CreationDate>1382441621</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456555</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o75">
<a:ObjectID>2171D62B-F633-450E-9016-9CB68C529190</a:ObjectID>
<a:Name>tryJoin</a:Name>
<a:Code>tryJoin</a:Code>
<a:CreationDate>1382790574</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987755</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
<o:Operation Id="o78">
<a:ObjectID>25926CD4-7901-4FC8-9D0D-0FF1AB8294AF</a:ObjectID>
<a:Name>timedJoin</a:Name>
<a:Code>timedJoin</a:Code>
<a:CreationDate>1382790580</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987755</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<c:Parameters>
<o:Parameter Id="o147">
<a:ObjectID>BA759029-391B-4960-AA5F-276B0BF96062</a:ObjectID>
<a:Name>msec</a:Name>
<a:Code>msec</a:Code>
<a:CreationDate>1382790625</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382790632</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o80">
<a:ObjectID>2B154FD9-96A5-4A84-BADD-478B8453EDCD</a:ObjectID>
<a:Name>isLaunched</a:Name>
<a:Code>isLaunched</a:Code>
<a:CreationDate>1382987679</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382987755</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
</o:Operation>
</c:Operations>
</o:Interface>
<o:Interface Id="o51">
<a:ObjectID>88136DF8-0882-4A97-A87D-BC637E138005</a:ObjectID>
<a:Name>IMutex</a:Name>
<a:Code>IMutex</a:Code>
<a:CreationDate>1382441669</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Operations>
<o:Operation Id="o116">
<a:ObjectID>522A5C5D-D0B4-4469-A37F-E21F2E7E43EB</a:ObjectID>
<a:Name>lock</a:Name>
<a:Code>lock</a:Code>
<a:CreationDate>1382441687</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o118">
<a:ObjectID>47ADD174-08E2-473B-8A08-DD8F7BC45992</a:ObjectID>
<a:Name>unlock</a:Name>
<a:Code>unlock</a:Code>
<a:CreationDate>1382441687</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>void</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o120">
<a:ObjectID>90216860-5B34-43D2-B999-C315AE964093</a:ObjectID>
<a:Name>trylock</a:Name>
<a:Code>trylock</a:Code>
<a:CreationDate>1382441687</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382792970</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
</c:Operations>
</o:Interface>
<o:Interface Id="o52">
<a:ObjectID>FB64044F-3CA1-47A4-80FB-CD2B6453B27F</a:ObjectID>
<a:Name>ICondVar</a:Name>
<a:Code>ICondVar</a:Code>
<a:CreationDate>1382441716</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441771</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:UseParentNamespace>0</a:UseParentNamespace>
<a:Classifier.Abstract>1</a:Classifier.Abstract>
<c:Operations>
<o:Operation Id="o129">
<a:ObjectID>6B2C572E-879E-4561-AAAB-EA7C7687E3CB</a:ObjectID>
<a:Name>wait</a:Name>
<a:Code>wait</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456632</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o148">
<a:ObjectID>B8811177-EACA-4778-9170-B968FC68B459</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441771</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
<o:Operation Id="o131">
<a:ObjectID>40D58349-83E3-4E62-93C8-7C64858EF04A</a:ObjectID>
<a:Name>signal</a:Name>
<a:Code>signal</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456632</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o133">
<a:ObjectID>08D8B2BB-1FFA-40F2-9F50-4BD0443A01FB</a:ObjectID>
<a:Name>broadcast</a:Name>
<a:Code>broadcast</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456632</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
</o:Operation>
<o:Operation Id="o137">
<a:ObjectID>80989ADB-835D-4689-8819-15460EA31A0A</a:ObjectID>
<a:Name>timedWait</a:Name>
<a:Code>timedWait</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382456632</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:ReturnType>boolean</a:ReturnType>
<a:Operation.Abstract>1</a:Operation.Abstract>
<a:TemplateBody>%DefaultBody%</a:TemplateBody>
<c:Parameters>
<o:Parameter Id="o149">
<a:ObjectID>46BB96AF-D80C-4888-8B4E-D34DACB40068</a:ObjectID>
<a:Name>mutex</a:Name>
<a:Code>mutex</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441771</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:Parameter.DataType>Mutex&amp;</a:Parameter.DataType>
</o:Parameter>
<o:Parameter Id="o150">
<a:ObjectID>FA7F8E87-E1CC-4F00-9C66-C94DF162A2C6</a:ObjectID>
<a:Name>usec</a:Name>
<a:Code>usec</a:Code>
<a:CreationDate>1382441764</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441771</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<a:Parameter.DataType>unsigned int</a:Parameter.DataType>
</o:Parameter>
</c:Parameters>
</o:Operation>
</c:Operations>
</o:Interface>
</c:Interfaces>
<c:Generalizations>
<o:Generalization Id="o8">
<a:ObjectID>D71BD400-7682-455B-A3F8-E422D97E513E</a:ObjectID>
<a:Name>Generalisation_3</a:Name>
<a:Code>Generalisation_3</a:Code>
<a:CreationDate>1382431883</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382431904</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si windows</a:Stereotype>
<c:Object1>
<o:Class Ref="o41"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o43"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o11">
<a:ObjectID>21041B28-B551-48A0-94DD-7EF90EDC1398</a:ObjectID>
<a:Name>Generalisation_4</a:Name>
<a:Code>Generalisation_4</a:Code>
<a:CreationDate>1382431893</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382431909</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si unix</a:Stereotype>
<c:Object1>
<o:Class Ref="o42"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o43"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o15">
<a:ObjectID>93B241C1-308C-4D58-B1AC-0B7E9AA76C81</a:ObjectID>
<a:Name>Generalisation_8</a:Name>
<a:Code>Generalisation_8</a:Code>
<a:CreationDate>1382439582</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439595</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si windows</a:Stereotype>
<c:Object1>
<o:Class Ref="o44"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o46"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o18">
<a:ObjectID>BBC63443-E286-4377-BBEE-7AF631857231</a:ObjectID>
<a:Name>Generalisation_9</a:Name>
<a:Code>Generalisation_9</a:Code>
<a:CreationDate>1382439583</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439589</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si unix</a:Stereotype>
<c:Object1>
<o:Class Ref="o45"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o46"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o22">
<a:ObjectID>220A0B04-DFE1-4BF8-A974-5F6ACE4639DF</a:ObjectID>
<a:Name>Generalisation_12</a:Name>
<a:Code>Generalisation_12</a:Code>
<a:CreationDate>1382439975</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439990</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si windows</a:Stereotype>
<c:Object1>
<o:Class Ref="o47"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o49"/>
</c:Object2>
</o:Generalization>
<o:Generalization Id="o25">
<a:ObjectID>43E81B66-320F-4A1D-9F66-BC43A655ABB7</a:ObjectID>
<a:Name>Generalisation_13</a:Name>
<a:Code>Generalisation_13</a:Code>
<a:CreationDate>1382439976</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382439995</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:Stereotype>si unix</a:Stereotype>
<c:Object1>
<o:Class Ref="o48"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o49"/>
</c:Object2>
</o:Generalization>
</c:Generalizations>
<c:Realizations>
<o:Realization Id="o28">
<a:ObjectID>BEB796DF-CD8B-4270-89B4-49EEC4B5EB8E</a:ObjectID>
<a:Name>Realisation_1</a:Name>
<a:Code>Realisation_1</a:Code>
<a:CreationDate>1382441653</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441653</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o50"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o41"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o30">
<a:ObjectID>71B7B575-C820-4F42-85F6-B6F0796DB54D</a:ObjectID>
<a:Name>Realisation_2</a:Name>
<a:Code>Realisation_2</a:Code>
<a:CreationDate>1382441654</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441654</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o50"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o42"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o33">
<a:ObjectID>8ACD1C3D-83E8-4E07-8863-A79665DC55E7</a:ObjectID>
<a:Name>Realisation_3</a:Name>
<a:Code>Realisation_3</a:Code>
<a:CreationDate>1382441700</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441700</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o51"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o44"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o35">
<a:ObjectID>74625986-C848-404C-BA71-977D14CFFFA7</a:ObjectID>
<a:Name>Realisation_4</a:Name>
<a:Code>Realisation_4</a:Code>
<a:CreationDate>1382441702</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441702</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o51"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o45"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o38">
<a:ObjectID>D5B96D8E-B788-41E0-B052-E5FBDF308656</a:ObjectID>
<a:Name>Realisation_5</a:Name>
<a:Code>Realisation_5</a:Code>
<a:CreationDate>1382441779</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441779</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o52"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o47"/>
</c:Object2>
</o:Realization>
<o:Realization Id="o40">
<a:ObjectID>73D0299E-C64B-4050-BE1C-D6F3B1499148</a:ObjectID>
<a:Name>Realisation_6</a:Name>
<a:Code>Realisation_6</a:Code>
<a:CreationDate>1382441780</a:CreationDate>
<a:Creator>D2P2</a:Creator>
<a:ModificationDate>1382441780</a:ModificationDate>
<a:Modifier>D2P2</a:Modifier>
<c:Object1>
<o:Interface Ref="o52"/>
</c:Object1>
<c:Object2>
<o:Class Ref="o48"/>
</c:Object2>
</o:Realization>
</c:Realizations>
<c:TargetModels>
<o:TargetModel Id="o151">
<a:ObjectID>2AF49998-28B6-480B-AC69-04232C2DE265</a:ObjectID>
<a:Name>Analyse</a:Name>
<a:Code>Analysis</a:Code>
<a:CreationDate>1382428594</a:CreationDate>
<a:Creator>Julien</a:Creator>
<a:ModificationDate>1382428594</a:ModificationDate>
<a:Modifier>Julien</a:Modifier>
<a:TargetModelURL>file:///%_OBJLANG%/analysis.xol</a:TargetModelURL>
<a:TargetModelID>87317290-AF03-469F-BC1E-99593F18A4AB</a:TargetModelID>
<a:TargetModelClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetModelClassID>
<c:SessionShortcuts>
<o:Shortcut Ref="o3"/>
</c:SessionShortcuts>
</o:TargetModel>
</c:TargetModels>
</o:Model>
</c:Children>
</o:RootObject>

</Model>