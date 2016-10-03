<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1024.0000" Y="768.0000" />
        <Children>
          <AbstractNodeData Name="spaceShip" ActionTag="1967390300" Tag="7" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="488.5000" RightMargin="488.5000" TopMargin="691.2000" BottomMargin="42.8000" ctype="SpriteObjectData">
            <Size X="47.0000" Y="34.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="512.0000" Y="76.8000" />
            <Scale ScaleX="1.0000" ScaleY="0.9440" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1000" />
            <PreSize X="0.0459" Y="0.0443" />
            <FileData Type="Normal" Path="assets/Player/spaceship.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="shield1" ActionTag="1508773094" Tag="9" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="159.8000" RightMargin="774.2000" TopMargin="581.8000" BottomMargin="115.2000" ctype="SpriteObjectData">
            <Size X="90.0000" Y="71.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="204.8000" Y="115.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2000" Y="0.1500" />
            <PreSize X="0.0879" Y="0.0924" />
            <FileData Type="Normal" Path="assets/Player/player_shield.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="shield2" ActionTag="-2003852049" Tag="10" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="364.6000" RightMargin="569.4000" TopMargin="581.8000" BottomMargin="115.2000" ctype="SpriteObjectData">
            <Size X="90.0000" Y="71.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="409.6000" Y="115.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4000" Y="0.1500" />
            <PreSize X="0.0879" Y="0.0924" />
            <FileData Type="Normal" Path="assets/Player/player_shield.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="shield3" ActionTag="361240055" Tag="11" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="569.4000" RightMargin="364.6000" TopMargin="581.8000" BottomMargin="115.2000" ctype="SpriteObjectData">
            <Size X="90.0000" Y="71.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="614.4000" Y="115.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6000" Y="0.1500" />
            <PreSize X="0.0879" Y="0.0924" />
            <FileData Type="Normal" Path="assets/Player/player_shield.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="shield4" ActionTag="-1853259461" Tag="12" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="774.2000" RightMargin="159.8000" TopMargin="581.8000" BottomMargin="115.2000" ctype="SpriteObjectData">
            <Size X="90.0000" Y="71.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="819.2000" Y="115.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8000" Y="0.1500" />
            <PreSize X="0.0879" Y="0.0924" />
            <FileData Type="Normal" Path="assets/Player/player_shield.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scoreLabel" ActionTag="759840526" Tag="13" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="51.2000" RightMargin="850.8000" TopMargin="38.4000" BottomMargin="688.6000" FontSize="30" LabelText="SCORE:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="122.0000" Y="41.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="51.2000" Y="729.6000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0500" Y="0.9500" />
            <PreSize X="0.1191" Y="0.0534" />
            <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="score" ActionTag="-1850490549" Tag="14" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="204.8000" RightMargin="797.2000" TopMargin="38.4000" BottomMargin="688.6000" FontSize="30" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="22.0000" Y="41.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="204.8000" Y="729.6000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2000" Y="0.9500" />
            <PreSize X="0.0215" Y="0.0534" />
            <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="enemyNode" ActionTag="-357746900" Tag="30" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="102.4000" RightMargin="921.6000" TopMargin="307.2000" BottomMargin="460.8000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="102.4000" Y="460.8000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.6000" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="startLabel" ActionTag="-1336591230" Tag="43" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="369.0000" RightMargin="369.0000" TopMargin="356.0000" BottomMargin="356.0000" FontSize="20" LabelText="TAP ANYWHERE TO START&#xA;" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="286.0000" Y="56.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="512.0000" Y="384.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.2793" Y="0.0729" />
            <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="gameOverPanel" ActionTag="-1925443532" VisibleForFrame="False" Tag="18" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="512.0000" RightMargin="512.0000" TopMargin="330.2400" BottomMargin="437.7600" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="gameOverLabel" ActionTag="-61030859" Tag="14" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="-144.0000" RightMargin="-144.0000" TopMargin="-127.5000" BottomMargin="72.5000" FontSize="40" LabelText="Game     Over" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="288.0000" Y="55.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="100.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="finalScoreLabel" ActionTag="-461658290" Tag="15" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-95.0000" RightMargin="-95.0000" TopMargin="-17.0000" BottomMargin="-17.0000" FontSize="25" LabelText="Final Score" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="190.0000" Y="34.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="restartLabel" ActionTag="-994670992" Tag="16" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="-158.0000" RightMargin="-158.0000" TopMargin="136.0000" BottomMargin="-164.0000" FontSize="20" LabelText="Tap anywhere to restart" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="316.0000" Y="28.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-150.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="finalScore" ActionTag="-1911736385" Tag="17" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="-9.5000" RightMargin="-9.5000" TopMargin="58.0000" BottomMargin="-92.0000" FontSize="25" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="19.0000" Y="34.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-75.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="assets/space_invaders.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="512.0000" Y="437.7600" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5700" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>