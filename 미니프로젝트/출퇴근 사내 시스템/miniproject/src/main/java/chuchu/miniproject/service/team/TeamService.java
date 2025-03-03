package chuchu.miniproject.service.team;

import chuchu.miniproject.domain.Team;
import chuchu.miniproject.dto.user.request.RequestSaveTeam;
import chuchu.miniproject.dto.user.response.ResponseGetTeam;
import chuchu.miniproject.repository.team.TeamRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
public class TeamService {

    private final TeamRepository teamRepository;


    @Transactional
    public void saveTeam (RequestSaveTeam requestSaveTeam) {
        Team team = teamRepository.save(new Team(requestSaveTeam.getName(),
                                                requestSaveTeam.getManager(),
                                                requestSaveTeam.getMemberCount()));
    }

    @Transactional
    public List<ResponseGetTeam> getTeams() {
        return teamRepository.findAll().stream()
                .map(ResponseGetTeam ::new)
                .collect(Collectors.toList());
    }

}
